#include<iostream>
#include<windows.h>
#include<mysql/mysql.h>
#include<sstream>

using namespace std;

int main(){
MYSQL* conn;
MYSQL_ROW row;//
MYSQL_RES* res;//

    conn=mysql_init(0);

    conn=mysql_real_connect(conn,"192.168.0.104","admin","admin","test_db",0,NULL,0);//(conn, ip address, db_username, db_password , database_name)
    if(conn){
        printf("Connected");
    }
    else{
        printf("Not Connected");
    }


/*
    int qstate=0;
    stringstream ss;
    string name="rohan";
    ss<<"INSERT INTO `che`(`name`) VALUES('"<<name<<"')";
    cout<<endl<<"INSERT INTO `che`(`name`) VALUES ('hello')"<<endl;
    cout<<"INSERT INTO `che`(`name`) VALUES(`"<<name<<"`)"<<endl;
    string query =ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn,q);
    if(qstate==0){
        cout<<"Inserted"<<endl;
    }else{
        cout<<"Failed"<<endl;
    }
*/

    if(conn){
        int qstate =mysql_query(conn,"SELECT * from `che`");

        if(!qstate){
            res=mysql_store_result(conn);

            while(row=mysql_fetch_row(res)){
                cout<<row[0]<< " " <<row[1]<<endl;
            }
        }
    }


return 0;
}
