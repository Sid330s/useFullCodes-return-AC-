#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

vector<string>lt;
vector<int> lm(20,0);
vector<pair<string,int>>st;
map<int,string>in;
vector<int> pool;
vector<vector<string>>target;
vector<vector<pair<string,string>>> inter;




string tab1(string k)
{

  unordered_map<string,string> clas;

  clas["STOP"]="IS";
  clas["ADD"]="IS";
  clas["SUB"]="IS";
  clas["MULTI"]="IS";
  clas["MOVER"]="IS";
  clas["MOVEM"]="IS";
  clas["COMB"]="IS";
  clas["BC"]="IS";
  clas["DIV"]="IS";
  clas["READ"]="IS";
  clas["PRINT"]="IS";
  clas["AREG"]="REG";
  clas["BREG"]="REG";
  clas["CREG"]="REG";
  clas["END"]="AD";
  clas["START"]="AD";
  clas["LTORG"]="AD";
  clas["DS"]="DL";
  clas["DC"]="DL";





       return clas[k] ;



}

string tab2(string k)
{

  unordered_map<string,string> clas;

  clas["STOP"]="00";
  clas["ADD"]="01";
  clas["SUB"]="02";
  clas["MULTI"]="03";
  clas["MOVER"]="04";
  clas["MOVEM"]="05";
  clas["COMB"]="06";
  clas["BC"]="07";
  clas["DIV"]="08";
  clas["READ"]="09";
  clas["PRINT"]="10";


  clas["AREG"]="01";
  clas["BREG"]="02";
  clas["CREG"]="03";

  clas["END"]="02";
  clas["START"]="01";
  clas["LTORG"]="05";

  clas["DS"]="01";
  clas["DC"]="02";



       return clas[k];



}

int nem(string k)
{
    vector<string> c;
    c.push_back("STOP");
    c.push_back("ADD");
    c.push_back("SUB");
    c.push_back("MULTI");
    c.push_back("MOVER");
    c.push_back("MOVEM");
    c.push_back("COMB");
    c.push_back("BC");
    c.push_back("DIV");
    c.push_back("READ");
    c.push_back("PRINT");
    c.push_back("EQU");
    c.push_back("CREG");
    c.push_back("BREG");
    c.push_back("AREG");



    auto it = find(c.begin(),c.end(), k);
    if(it!=c.end())
    {
        return(0);//symboll
    }
    else if(k.substr(0,2)=="='")
    {
        return(2);//literal
    }
    else if(k=="START")
    {
        return(3);
    }
    else if(k=="LTORG")
    {
    	return(4);
    }
     else if(k=="END")
    {
    	return(5);
    }
     else if(k=="ORIGIN")
    {
    	return(6);
    }
    else if(k=="DS" || k=="DC")
    {
        return(7);
    }
    else if(k==":")
    {
        return(8);
    }

    else
    {
        return 1;
    }


}

vector<string>  demolish(string a)
{
	//string a="77 yyy iiii ttt ";
	 vector<string> v;
    string l;
    int i=0;
    while(i<a.size())
    {
        if(a[i]==' ')
        {
            v.push_back(l);
            l="";
        }
        else
        {
            l=l+a[i];
        }

        i++;
    }
    v.push_back(l);

    return v;
}

int main(){
fstream newfile;
 int start=0;
 pool.push_back(0);
newfile.open("f1.txt",ios::in); //open a file to perform read operation using file object
int countline=0;
if (newfile.is_open()){
 string tp;
	while(getline(newfile, tp)){
				        int i=0,flag=0;
				         vector<pair<string,string>> inte;

				        vector<string> line=demolish(tp);
				         while(i<line.size())
				        {
			                           int index=nem(line[i]);
			                           int k=0;


			                            if(index==0)
							            {   flag=1;
							            	inte.push_back(make_pair(tab1(line[i]),tab2(line[i])));


							            	i++;
			                               continue;

							            }
							            else if(index==1 )
							            {   cout<<"{"<<line[i]<<"}";

							            	int flag1=0;
							            	int k=0;
			                                 for(int j=0;j<st.size();j++)
			                                 	{ if(line[i]==st[j].first)
                                                    {
                                                      flag1=1;
                                                      break;
                                                    }

			                                 	}

							                if(flag1!=1)
							            	    st.push_back(make_pair(line[i],0));

							            	if(i==0)
							            		{   int j=0;
							            			while(st[j].first!=line[i] && j<st.size())
							            			{
							            				j++;
							            				break;
							            			}

							            			st[j].second=start;
							            		}



                                            	while(st[k].first!=line[i] && k<st.size())
							            			{
							            				k++;
							            			}


			                                     inte.push_back(make_pair("S",to_string(k)));


							            }
							            else if(index==2 )
							            {
							            	int j=0, k=line[i].find("'",2);
							                if(find(lt.begin(),lt.end(),line[i].substr(2,k-2))==lt.end())
							                    lt.push_back(line[i].substr(2,k-2));

							                while(lt[j]!=line[i] && j<lt.size())
							            			{
							            				j++;
							            			}


							                inte.push_back(make_pair("L",to_string(j-1)));


							            }
							            else if(index==3 )
							            {
							                start=stoi( line[i+1] )-1;
							                inte.push_back(make_pair(tab1(line[i]),tab2(line[i])));
							                inte.push_back(make_pair("C",to_string(start+1)));
							                break;

							            }
			            	            else if(index==4)
							            {

							                for(int k=pool[pool.size()-1];k<lt.size();k++)
							                {   vector<pair<string,string>> inte1;
							                	lm[k]=start;
							                	inte1.push_back(make_pair(tab1(line[i]),tab2(line[i])));
							                	inte1.push_back(make_pair("DL",to_string(2)));
							                	inte1.push_back(make_pair("C",lt[k]));
							                	inter.push_back(inte1);
							                	start++;
							                }
			                                start--;
			                                //inter.pop_back();

							                pool.push_back(lt.size());



							                break;

							            }
							            else if(index==5)
							            {

							            	for(int k=pool[pool.size()-1];k<lt.size();k++)
							                {
							                	vector<pair<string,string>> inte1;
							                	lm[k]=start;
							                	inte1.push_back(make_pair(tab1(line[i]),tab2(line[i])));
							                	inte1.push_back(make_pair("DL",to_string(2)));
							                	inte1.push_back(make_pair("C",lt[k]));
							                	inter.push_back(inte1);
							                	start++;
							                }
			                                start--;
			                                //inter.pop_back();

							                break;


							            }
							            else if(index==6)
							            {   int j=0;
							                while(st[j].first!=line[i] && j<st.size())
							            			{
							            				j++;
							            			}

							            	 if(line.size()>=3)
							                  {
							                  	start= st[j-1].second+stoi(line[3])-1;

							                  }
							                   if(line.size()==2)
							                   {
							                   	start=stoi(line[1])-1;
							                   }

							                  break;
							            }
							            else if(index==7)
							            {
							                start=start+ stoi(line[i+1])-1;
							                 inte.push_back(make_pair("DL",to_string(1)));
							                 inte.push_back(make_pair("C",line[i+1]));
							                break;
							            }

							            else if(index==8)
							            {   i++;
							            	continue;
							            }

                             i++;



                        }

                       /*cout<<"("<<small.size()<<")";
                        for(int i=0;i<small.size();i++)
					        {
					         cout<<" ["<<small[i]<<"] ";
					        }*/

                        inter.push_back(inte);
                        cout<<"["<<start<<"]";
                        start++;

	                    countline++;

				    }
				}
           for(int i=1;i<inter.size();i++){
           	  vector<string> temp;
           	  int flag3=0;
			  for(int j=0;j<inter[i].size();j++)
			  {
			  	if(inter[i][j].first=="IS")
			  	{
			  		flag3=1;
			  		temp.push_back(inter[i][j].second);
			  	}
			  	if(inter[i][j].first=="AD")
			  	{
			  		 temp.push_back("<->");
			  		 temp.push_back("<->");

			  	}
			  	if(inter[i][j].first=="C")
			  	{  temp.push_back(inter[i][j].second);

			  	}
			  	if(flag3==1)
			  	{  if(inter[i][j].first=="REG")
                      temp.push_back(inter[i][j].second);
                   int s=stoi(inter[i][j].second);

                 if(inter[i][j].first=="L" )
                      temp.push_back(to_string(lm[s]));
                 if(inter[i][j].first=="S" )
                      temp.push_back(to_string(st[s].second));

			    }


			  	}
			  	target.push_back(temp);
		}

        cout<<endl;

		for(int i=0;i<inter.size();i++){
		  for(int j=0;j<inter[i].size();j++)
		  {
		     cout<<"["<<inter[i][j].first<<" , "<<inter[i][j].second<<"]"<<"  ";
		  }
		  cout<<endl;
		}

		 cout<<"Symbol Table"<<endl;
         for(int itr=0;itr<st.size();itr++)
        {
         cout<<st[itr].first<<" "<<st[itr].second<<endl;
        }
        cout<<endl;
        cout<<"Literal Table"<<endl;
        for(int i=0;i<lt.size();i++)
        {
         cout<<lt[i]<<" "<<lm[i]<<endl;
        }
        cout<<endl;
        cout<<"Pool Table"<<endl;
        for (int i=0;i<pool.size();i++)
        {
            cout<<pool[i]<<endl;
        }
        cout<<endl;
        cout<<"target code"<<endl;
        for (int i=0;i<target.size();i++)
        {  for (int j=0;j<target[i].size();j++)
        {
            cout<<target[i][j]<<" ";
        }
           cout<<endl;
        }
         //cout<<"incomplete code"<<endl;
        cout<<endl;
       for(auto itr=in.begin();itr!=in.end();++itr)
        {
         cout<<itr->first<<" "<<itr->second<<endl;
        }

    return 0;
}
/*
#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

vector<string>lt;
vector<int> lm(20,0);
unordered_map<string,int>st;
map<int,string>in;
vector<int> pool;
vector<vector<string>>target;




int tab1(string k)
{

  unordered_map<string,string> clas;

  clas["STOP"]="IS";
  clas["ADD"]="IS";
  clas["SUB"]="IS";
  clas["MULTI"]="IS";
  clas["MOVER"]="IS";
  clas["MOVEM"]="IS";
  clas["COMB"]="IS";
  clas["BC"]="IS";
  clas["DIV"]="IS";
  clas["READ"]="IS";
  clas["PRINT"]="IS";
  clas["AREG"]="R";
  clas["BREG"]="R";
  clas["CREG"]="R";



   if(clas[k]=="IS")
       return 1;
   else if(clas[k]=="R")
      return 2;
    else return 0;


}

string tab2(string k)
{

  unordered_map<string,string> clas;

  clas["STOP"]="00";
  clas["ADD"]="01";
  clas["SUB"]="02";
  clas["MULTI"]="03";
  clas["MOVER"]="04";
  clas["MOVEM"]="05";
  clas["COMB"]="06";
  clas["BC"]="07";
  clas["DIV"]="08";
  clas["READ"]="09";
  clas["PRINT"]="10";


  clas["AREG"]="01";
  clas["BREG"]="02";
  clas["CREG"]="03";




   if(clas.find(k)!=clas.end())
       return clas[k];
   else
      return 0;


}

int nem(string k)
{
    vector<string> c;
    c.push_back("STOP");
    c.push_back("ADD");
    c.push_back("SUB");
    c.push_back("MULTI");
    c.push_back("MOVER");
    c.push_back("MOVEM");
    c.push_back("COMB");
    c.push_back("BC");
    c.push_back("DIV");
    c.push_back("READ");
    c.push_back("PRINT");
    c.push_back("EQU");
    c.push_back("CREG");
    c.push_back("BREG");
    c.push_back("AREG");



    auto it = find(c.begin(),c.end(), k);
    if(it!=c.end())
    {
        return(0);//symboll
    }
    else if(k.substr(0,2)=="='")
    {
        return(2);//literal
    }
    else if(k=="START")
    {
        return(3);
    }
    else if(k=="LTORG")
    {
    	return(4);
    }
     else if(k=="END")
    {
    	return(5);
    }
     else if(k=="ORIGIN")
    {
    	return(6);
    }
    else if(k=="DS" || k=="DC")
    {
        return(7);
    }
    else if(k==":")
    {
        return(8);
    }

    else
    {
        return 1;
    }


}

vector<string>  demolish(string a)
{
	//string a="77 yyy iiii ttt ";
	 vector<string> v;
    string l;
    int i=0;
    while(i<a.size())
    {
        if(a[i]==' ')
        {
            v.push_back(l);
            l="";
        }
        else
        {
            l=l+a[i];
        }

        i++;
    }
    v.push_back(l);

    return v;
}

int main(){
fstream newfile;
 int start=0,flag2=0;
 pool.push_back(0);
newfile.open("f1.txt",ios::in); //open a file to perform read operation using file object
int countline=0;
if (newfile.is_open()){
 string tp;
	while(getline(newfile, tp)){
				        int i=0,flag=0;
				         vector<string> small(3);

				        vector<string> line=demolish(tp);
				         while(i<line.size())
				        {
                           int index=nem(line[i]);


                            if(index==0)
				            {
				            	int k=tab1(line[i]);
				            	if(k==1)
				            	{
				            		flag=1;
				            		small.push_back(tab2(line[i]));

				            	}

				            	if(k==2 && flag==1)
				            	{
                                    small.push_back(tab2(line[i]));
				            	}



				            	i++;
                               continue;

				            }
				            else if(index==1 )
				            {
                                 cout<<"hiii";
				                if(st.find(line[i])==st.end())
				            	    st[line[i]]=0;

				            	if(i==0)
				            		st[line[i]]=start;

                               if(flag==1)  {
				            	if(st[line[i]]==0)
				            	{
                                       in[countline+flag2]=line[i];
				            	}
				            	else
				            	{

				            		 small.push_back(to_string(st[line[i]]));
				            	}
				               }


				            }
				            else if(index==2 )
				            {
				            	int k=line[i].find("'",2);
				                if(find(lt.begin(),lt.end(),line[i].substr(2,k-2))==lt.end())
				                    lt.push_back(line[i].substr(2,k-2));



                               if(flag==1)  {
                                auto it=find(lt.begin(),lt.end(),line[i].substr(2,k-2));
                                int l=distance(lt.begin(),it);



				                if(lm[l]==0)
				            	{

                                  in[countline+flag2]=line[i].substr(2,k-2);
				            	}
				            	else
				            	{
			                   small.push_back(to_string(lm[l]));
				            	}
				            }

				              cout<<start<<" )";

				            }
				            else if(index==3 )
				            {
				                start=stoi( line[i+1] )-1;

				                break;



				            }
            	            else if(index==4)
				            {
				                for(int k=pool[pool.size()-1];k<lt.size();k++)
				                {   vector<string>smalli(3);
				                	lm[k]=start;
				                	smalli.push_back("<->");
				                	smalli.push_back("<->");
				                	smalli.push_back(lt[k]);

				                	target.push_back(smalli);

				                	flag2++;

				                	start++;
				                }
                                 start--;

				                pool.push_back(lt.size());






				                break;

				            }
				            else if(index==5)
				            {   cout<<start<<"uu"<<pool.size()-1<<lt.size();
				            	for(int k=pool[pool.size()-1];k<lt.size();k++)
				                {	vector<string>smalli(3);
				                	lm[k]=start;
				                	smalli.push_back("<->");
				                	smalli.push_back("<->");
				                	smalli.push_back(lt[k]);

				                	target.push_back(smalli);



				                	start++;
				                }

				                break;


				            }
				            else if(index==6)
				            {     if(line.size()>=3)
				                  {
				                  	start= st[line[1]]+stoi(line[3])-1;
				                  	//stoi(221st[line[1]])
				                  }
				                   if(line.size()==2)
				                   {
				                   	start=stoi(line[1])-1;
				                   }

				                break;
				            }
				            else if(index==7)
				            {
				                start=start+ stoi(line[i+1])-1;
				                break;
				            }

				            else if(index==8)
				            {
				            	continue;
				            }

                             i++;



                        }

                       cout<<start;
                        target.push_back(small);

                        start++;

	                    countline++;

				    }
				}

       for(auto itr=in.begin();itr!=in.end();++itr)
        {
              auto it=find(lt.begin(),lt.end(),itr->second);
              if(it!=lt.end())
               {
               	int l=distance(lt.begin(),it);
               	target[itr->first].push_back(to_string(lm[l]));
               }
             else
               target[itr->first].push_back(to_string(st[itr->second]));


        }
        cout<<endl;

		 cout<<"Symbol Table"<<endl;
         for(auto itr=st.begin();itr!=st.end();++itr)
        {
         cout<<itr->first<<" "<<itr->second<<endl;
        }
        cout<<endl;
        cout<<"Literal Table"<<endl;
        for(int i=0;i<lt.size();i++)
        {
         cout<<lt[i]<<" "<<lm[i]<<endl;
        }
        cout<<endl;
        cout<<"Pool Table"<<endl;
        for (int i=0;i<pool.size();i++)
        {
            cout<<pool[i]<<endl;
        }
        cout<<endl;
        cout<<"target code"<<endl;
        for (int i=0;i<target.size();i++)
        {  for (int j=0;j<target[i].size();j++)
        {
            cout<<target[i][j]<<" ";
        }
           cout<<endl;
        }
         cout<<"incomplete code"<<endl;
        cout<<endl;
       for(auto itr=in.begin();itr!=in.end();++itr)
        {
         cout<<itr->first<<" "<<itr->second<<endl;
        }

    return 0;
}*/
