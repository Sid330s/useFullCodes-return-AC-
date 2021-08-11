import xml.etree.ElementTree as ET
from os import walk
import os
import graphviz
from jproperties import Properties

SOFTWARES_PATH = input("Enter Software path, \n Example:- C:\\Program Files\\DeploymentCenter\\repository\\software\\ \n input:")
PACKAGES_PATH = '\\dc_contributions\\packages\\'
PACKAGES_LANG_EN_US_PATH = '\\dc_contributions\\packages\\lang\\en_US\\'
ARTIFACTS_LANG_PATH = '\\dc_contributions\\artifacts\\lang\\'
COMPONENTS_PATH = '\\dc_contributions\\deployablecomponents\\'
COMPONENTS_LANG_PATH = '\\dc_contributions\\deployablecomponents\\lang\\'


package_object = {}
artifact_object = {}
software_object = {}
component_object ={}
get_software_details = {}
software_directory_paths = []

class Component:
    def __init__(self, component_id, component_file_path):
        self.component_id = component_id
        self.component_file_path = component_file_path
        self.component_display_name = "No Name"

    def get_component_display_name(self):
        return self.component_display_name

    def set_component_display_name(self,component_display_name):
        self.component_display_name = component_display_name

    def get_component_details(self):
        return 'Component: \n'+ self.component_display_name

    def set_component_file_path(self,component_file_path):
        self.component_file_path = component_file_path

    def get_component_display_name(self):
        return self.component_display_name

    def get_component_file_path(self):
        return self.component_file_path

class Artifact:
    def __init__(self, package_id, package_display_name):
        self.artifact_id = package_id
        self.artifact_display_name = package_display_name
        self.components = set()

    def get_artifact_display_name(self):
        return self.artifact_display_name

    def get_artifact_details(self):
        return 'Artifact: \n'+ self.artifact_display_name

    def get_components(self):
        return self.components

    def add_component(self,component_id):
        self.components.add(component_id)



class Package:
    def __init__(self, package_id, package_display_name):
        self.package_id = package_id
        self.package_display_name = package_display_name
        self.artifacts=set()


    def set_software_details(self,software_details):
        self.software_details = software_details

    def set_package_file_path(self,package_file_path):
        self.package_file_path = package_file_path

    def get_package_display_name(self):
        return self.package_display_name

    def get_package_file_path(self):
        return self.package_file_path

    def add_artifact(self,artifact_id):
        self.artifacts.add(artifact_id)

    def get_package_details(self):
        package_details = 'Application:\n'+ self.package_display_name + '\n' + '.'.join(self.software_details)
        return package_details

    def get_artifacts(self):
        return self.artifacts

class Software:
    def __init__(self, software_details, software_directory_name, software_display_name):
        self.software_details = software_details
        self.software_directory_name = software_directory_name
        self.software_display_name =  software_display_name
        self.dependent_packages=[]
        self.dependent_softwares=[]

    def get_software_details(self):
        return '.'.join(self.software_details)

    def get_software_directory_name(self):
        return self.software_directory_name

    def get_software_display_name(self):
        return self.software_display_name

    def get_dependent_packages(self):
        return self.dependent_packages

    def add_package(self,package_id):
        self.dependent_packages.append(package_id)

    def get_dependent_softwares(self):
        return self.dependent_softwares

    def add_software(self,software_details):
        self.dependent_softwares.append(software_details)

    def get_software_label(self):
        return 'Software:\n'+ self.software_display_name + '\n' +'.'.join(self.software_details)


def get_file_from_list(file_names,starts_with,ends_with):
    for file_name in file_names:
        if file_name.startswith(starts_with) and file_name.endswith(ends_with):
            return file_name
    return None

def populate_software_directory_paths(dir_path):
    path = SOFTWARES_PATH + dir_path
    dir_names = []
    file_names = []
    for (dirpath, dirnames, filenames) in walk(path):
        dir_names.extend(dirnames)
        file_names.extend(filenames)
        break

    software_media_teamcenter_filename = get_file_from_list(file_names,'media_teamcenter','.xml')

    if software_media_teamcenter_filename==None:
        for dir_name in dir_names:
            new_dir_path = dir_path + '\\' + dir_name
            populate_software_directory_paths(new_dir_path)
    else:
        software_directory_paths.append(dir_path)

def parse_and_store__package_display_name():
    for dir_path in software_directory_paths:
        en_us_language_path = SOFTWARES_PATH + dir_path + PACKAGES_LANG_EN_US_PATH
        file_names = []
        for (dirpath, dirnames, filenames) in walk(en_us_language_path):
            file_names.extend(filenames)
            break
        for file_name in file_names:
            if not file_name.endswith('DCBundle_en_US.xml'):
                continue
            path = en_us_language_path + file_name
            tree = ET.parse(path)
            root = tree.getroot()
            package_display_name = root.find('property').attrib.get('value')
            package_id = root.attrib.get('name')
            package_object[package_id] = Package(package_id,package_display_name)

def parse_and_store__artifact_display_name():
    for dir_path in software_directory_paths:
        language_path = SOFTWARES_PATH + dir_path + ARTIFACTS_LANG_PATH
        file_names = []
        for (dirpath, dirnames, filenames) in walk(language_path):
            file_names.extend(filenames)
            break
        for file_name in file_names:
            if (not file_name.endswith('_en_US.properties')) and (not file_name.endswith('locale.properties')):
                continue

            configs = Properties()
            path = SOFTWARES_PATH + dir_path + ARTIFACTS_LANG_PATH + file_name
            # print("Artifact lang :path",path)
            with open(path, 'rb') as read_prop:
                configs.load(read_prop)
            prop_view = configs.items()
            for item in prop_view:
                if len(item[0].split('.'))>1 and item[0].split('.')[1]=='displayName':
                    display_name=configs.get(item[0]).data
                    artifact_id=item[0].split('.')[0].lower()
                    artifact_object[artifact_id]=Artifact(artifact_id,display_name)
                    # if artifact_id == "fnd0_datamodelartifact":
                    #      print("YES")

def parse_and_store__component_file_path():
    for dir_path in software_directory_paths:
        components_directory_path = SOFTWARES_PATH + dir_path + COMPONENTS_PATH
        file_names = []
        for (dirpath, dirnames, filenames) in walk(components_directory_path):
            file_names.extend(filenames)
            break
        for file_name in file_names:
            if not file_name.endswith('_DCC.xml'):
                continue
            path = components_directory_path + file_name
            tree = ET.parse(path)
            root = tree.getroot()
            component_id = root.attrib.get('name')
            component_object[component_id]=Component(component_id,path)
            feature_artifacts = root.find('featureArtifacts')
            if(type(feature_artifacts)==type(None)):
                continue
            for artifact in feature_artifacts:
                artifact_id = artifact.attrib['value'].lower()
                artifact_object.get(artifact_id,Artifact(artifact_id,"No Name")).add_component(component_id)
                # if artifact_id == "fnd0_dataModelArtifact":
                #     print("YES")

def parse_and_store__component_display_name():
    for dir_path in software_directory_paths:
        language_path = SOFTWARES_PATH + dir_path + COMPONENTS_LANG_PATH
        file_names = []
        for (dirpath, dirnames, filenames) in walk(language_path):
            file_names.extend(filenames)
            break
        for file_name in file_names:
            if (not file_name.endswith('_en_US.properties')) and (not file_name.endswith('locale.properties')):
                continue
            configs = Properties()
            path = SOFTWARES_PATH + dir_path + COMPONENTS_LANG_PATH + file_name
            with open(path, 'rb') as read_prop:
                configs.load(read_prop)
            prop_view = configs.items()
            #print(type(prop_view))
            for item in prop_view:
                #print(item)
                if len(item[0].split('.'))>1 and item[0].split('.')[1]=='displayName' and item[0].split('.')[0] in component_object:
                    display_name=configs.get(item[0]).data
                    component_id=item[0].split('.')[0]
                    component_object[component_id].set_component_display_name(display_name)



def parse_and_store_software_details():
    for dir_path in software_directory_paths:
        software_directory_path = SOFTWARES_PATH + dir_path
        file_names = []
        for (dirpath, dirnames, filenames) in walk(software_directory_path):
            file_names.extend(filenames)
            break
        software_media_teamcenter_filename = get_file_from_list(file_names,'media_teamcenter','.xml')
        software_media_teamcenter_path = software_directory_path + '\\' + software_media_teamcenter_filename
        tree = ET.parse(software_media_teamcenter_path)
        root = tree.getroot()
        software_platform = root.find('platform').text
        software_id = root.find('application_id').text.lower()
        software_release = (root.find('version').text).split(':')[0]
        software_display_name = root.find('application_display_name').text
        software_details = (software_id,software_release,software_platform)
        software_object[software_details] = Software(software_details,dir_path,software_display_name)
        get_software_details[dir_path] = software_details
        dependencies = root.find('application_dependency')
        platform = root.find('platform').text
        if(type(dependencies)==type(None)):
            continue
        for dependancy in dependencies:
            if dependancy.attrib.get('optional','false')=='false':
                # print("testing-->",dependancy.attrib['id'].lower(),dependancy.attrib['release'],platform)
                software_object[software_details].add_software((dependancy.attrib['id'].lower(),dependancy.attrib['release'],platform))

def parse_and_store_package_details():
    for dir_path in software_directory_paths:
        packages_directory_path = SOFTWARES_PATH + dir_path + PACKAGES_PATH
        file_names = []
        for (dirpath, dirnames, filenames) in walk(packages_directory_path):
            file_names.extend(filenames)
            break
        for file_name in file_names:
            if not file_name.endswith('_package.xml'):
                continue
            path = packages_directory_path + file_name
            tree = ET.parse(path)
            root = tree.getroot()
            package_id = root.attrib.get('packageId')
            package_object[package_id] = package_object.get(package_id,Package(package_id,"Not_Named"))
            package_object[package_id].set_package_file_path(path)
            package_object[package_id] = package_object.get(package_id,Package(package_id,"Not_Named"))
            package_object[package_id].set_software_details(get_software_details[dir_path])
            for artifact in root.findall('artifact'):
                artifact_id=artifact.attrib.get('artifactType').lower()
                package_object[package_id].add_artifact(artifact_id)
            default_selection = root.find('defaultSelection')
            if type(default_selection)==type(None):
                continue
            if default_selection.attrib.get('value')!='true':
                continue
            software_details = get_software_details[dir_path]
            software_object[software_details].add_package(package_id)

def get_package_id_list(display_name):
    package_id_list = []
    for package_id in package_object:
        if package_object[package_id].get_package_display_name() == display_name:
            package_id_list.append(package_id)
    return package_id_list


def interrelate_software(software_details,tree_level,edge_set,software_node_set,g,overall_dependancies):
    software = software_object[software_details]
    software_node_set.add(software_details)
    for software_details in software.get_dependent_softwares():
        g.node(software.get_software_details(), shape='folder', fillcolor='aqua', style='filled',label=software.get_software_label())
        g.node(software_object[software_details].get_software_details(), shape='folder', fillcolor='aqua', style='filled',label=software_object[software_details].get_software_label())
        edge_set.add((software.get_software_details(), software_object[software_details].get_software_details()))
        overall_dependancies.add(('software',software_object[software_details].get_software_details(),'None'))
        if software_details not in software_node_set:
            interrelate_software(software_details,tree_level+1,edge_set,software_node_set,g,overall_dependancies)



def interrelate_packages(package_id,tree_level,edge_set,package_node_set,g,overall_dependancies):
    package_file_path = package_object[package_id].get_package_file_path()
    tree = ET.parse(package_file_path)
    root = tree.getroot()
    # print('          '*(tree_level)+'|->',package_object[package_id].get_package_display_name())
    dependencies = root.find('dependencies')
    package_node_set.add(package_id)
    if(type(dependencies)==type(None)):
        return
    for dependancy in dependencies:
        if dependancy.attrib.get('optional','false')=='false':
            g.node(package_id, label=package_object[package_id].get_package_details())
            g.node(dependancy.attrib['id'], label=package_object[dependancy.attrib['id']].get_package_details())
            edge_set.add((package_id,dependancy.attrib['id']))
            overall_dependancies.add(('package',package_object[dependancy.attrib['id']].get_package_display_name(),dependancy.attrib['id']))
            interrelate_packages(dependancy.attrib['id'],tree_level+1,edge_set,package_node_set,g,overall_dependancies)

def interrelate_components(component_id,tree_level,edge_set,visited,g,overall_dependancies):
    component_file_path = component_object[component_id].get_component_file_path()
    visited.add(component_id)
    tree = ET.parse(component_file_path)
    root = tree.getroot()
    # print('          '*(tree_level)+'|->',component_id)
    dependencies = root.find('componentDependencies')
    if(type(dependencies)==type(None)):
        return
    for dependancy in dependencies:
        if dependancy.attrib.get('optional','false')=='false':
            g.node(dependancy.attrib['value'], label=component_object[dependancy.attrib['value']].get_component_details(), shape='component', fillcolor='hotpink', style='filled')
            edge_set.add((component_id,dependancy.attrib['value']))
            overall_dependancies.add(('component',component_object[dependancy.attrib['value']].get_component_display_name(),dependancy.attrib['value']))
            if dependancy.attrib['value'] not in visited:
                interrelate_components(dependancy.attrib['value'],tree_level+1,edge_set,visited,g,overall_dependancies)

def gvfile_corrector(file):
    new_lines=[]
    f = open(file, "r")
    lines = f.readlines()
    i=0
    for line in lines:
        if i<2:
            new_lines.append(line)
        elif line[0]=='\t':
            new_lines.append(line)
        else:
            new_lines[-1]=new_lines[-1][:-1] + '\\n ' + line
        i=i+1
    f.close()
    f = open(file, "w")
    f.writelines(new_lines)
    f.close()

populate_software_directory_paths("")
parse_and_store_software_details()
parse_and_store__package_display_name()
parse_and_store__artifact_display_name()
parse_and_store__component_file_path()
parse_and_store__component_display_name()
parse_and_store_package_details()

# print(package_object['seec'].get_artifacts())
# print(artifact_object)


def software_graph():
    options = {}
    i = 1
    print("Sr. No.","SOFTWARE DISPLAY NAME".ljust(50),"SOFTAWRE DETAILS".ljust(30))
    for software_details in software_object:
        print(str(i).ljust(7),software_object[software_details].get_software_display_name().ljust(50),software_object[software_details].get_software_details().ljust(30))
        options[str(i)]=software_details
        i=i+1

    option = input('Enter Software Sr. No.:')
    software_details = options[option]
    software_details = software_details

    # activeworkspace 5.2.1 wntx64
    graph_file_name = './/'+ '_'.join(list(software_details)) + '.gv'
    g = graphviz.Digraph(comment=graph_file_name)


    overall_dependancies = set()
    edge_set = set()
    software_node_set = set()
    interrelate_software(software_details,0,edge_set,software_node_set,g,overall_dependancies)
    package_node_set = set()

    g.node(software_object[software_details].get_software_details(), shape='folder', fillcolor='aqua', style='filled',label=software_object[software_details].get_software_label())
    for software_details in software_node_set:
        for package_id in software_object[software_details].get_dependent_packages():
            g.node(package_id, label=package_object[package_id].get_package_details())
            edge_set.add(( software_object[software_details].get_software_details(), package_id))
            overall_dependancies.add(('package',package_object[package_id].get_package_display_name(),package_id))
            interrelate_packages(package_id,0,edge_set,package_node_set,g,overall_dependancies)

    component_node_set = set()

    for package_id in package_node_set :
        artifacts = package_object[package_id].get_artifacts()
        for artifact_id in artifacts:
            object = artifact_object.get(artifact_id,Artifact(artifact_id,"No Name"))
            # print("artifact:",artifact_id)
            components = object.get_components()
            # print("components:",components)
            for component_id in components:
                g.node(package_id, label=package_object[package_id].get_package_details())
                g.node(component_id, label=component_object[component_id].get_component_details(), shape='component', fillcolor='hotpink', style='filled')
                edge_set.add((package_id,component_id))
                component_node_set.add(component_id)
                overall_dependancies.add(('component',component_object[component_id].get_component_display_name(),component_id))
            overall_dependancies.add(('artifact',object.get_artifact_display_name(),artifact_id))

    visited=set()
    for component_id in component_node_set:
        interrelate_components(component_id,0,edge_set,visited,g,overall_dependancies)


    g.edges(list(edge_set))
    try:
        g.render(graph_file_name, view=True)
        gvfile_corrector(graph_file_name)
    except:
        print("CLOSE THE PDF FILES !!!")
    dependancy_file_name=graph_file_name+'dependencies'+'.txt'
    with open(dependancy_file_name,'w',encoding = 'utf-8') as f:
        f.write('.'.join(list(software_details)) +':\n')
        for dependancy in overall_dependancies:
            x=0
            if(dependancy[0]=='component'):
                x=16
            if(dependancy[0]=='package'):
                x=8
            if(dependancy[0]=='artifact'):
                x=24
            f.write( ' '*x + '     -->' + dependancy[0] + ' ' + dependancy[1] + ' ' + dependancy[2] + '\n')

def application_graph():
    package_display_name=input('Enter Application name:')
    package_id_list = get_package_id_list(package_display_name)

    if len(package_id_list)==0:
        raise KeyError('NO SUCH APPLICATION !!')
    # Aerospace and Defense Foundation
    for package_id in package_id_list:
        overall_dependancies = set()
        graph_file_name = './/'+ package_display_name+'.'+package_id + '.gv'
        g = graphviz.Digraph(comment=package_id, node_attr={'color': 'black'})

        package_node_set = set()
        edge_set = set()

        interrelate_packages(package_id,0,edge_set,package_node_set,g,overall_dependancies)

        component_node_set = set()

        for package_id in package_node_set :
            artifacts = package_object[package_id].get_artifacts()
            for artifact_id in artifacts:
                object = artifact_object.get(artifact_id,Artifact(artifact_id,"No Name"))
                components = object.get_components()
                for component_id in components:
                    g.node(package_id, label=package_object[package_id].get_package_details())
                    g.node(component_id, label=component_object[component_id].get_component_details(), shape='component', fillcolor='hotpink', style='filled')
                    edge_set.add((package_id,component_id))
                    component_node_set.add(component_id)
                    overall_dependancies.add(('component',component_object[component_id].get_component_display_name(),component_id))
                overall_dependancies.add(('artifact',object.get_artifact_display_name(),artifact_id))

        visited=set()
        for component_id in component_node_set:
            interrelate_components(component_id,0,edge_set,visited,g,overall_dependancies)



        g.edges(list(edge_set))
        try:
            g.render(graph_file_name, view=True)
            gvfile_corrector(graph_file_name)
        except:
            print("CLOSE THE PDF FILES !!!")
        dependancy_file_name=graph_file_name+'dependencies'+'.txt'
        with open(dependancy_file_name,'w',encoding = 'utf-8') as f:
            f.write(package_display_name +':\n')
            for dependancy in overall_dependancies:
                x=0
                if(dependancy[0]=='component'):
                    x=16
                if(dependancy[0]=='package'):
                    x=8
                if(dependancy[0]=='artifact'):
                    x=24
                f.write( ' '*x + '     -->' + dependancy[0] + ' ' + dependancy[1] + ' ' + dependancy[2] + '\n')


while(True):
    print()
    print()
    print()
    print("GET GRAPH BY:-")
    print("1. Application")
    print("2. Software")
    choice = input("Enter Your Choice:")
    if choice=='1':
        try:
            application_graph()
        except :
            print("DEPENDENT SOFTWARE , APLLICATION OR COMPONENT NOT PRESENT !!!")
    elif choice=='2':
        try:
            software_graph()
        except :
            print("DEPENDENT SOFTWARE , APLLICATION OR COMPONENT NOT PRESENT !!!")
