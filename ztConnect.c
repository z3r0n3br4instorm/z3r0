#include<stdio.h>
#include<stdlib.h>
void master();
void ssh_ztccsyscnnect();
void ssh_connect();

int main(void)
{
	master();
	return 0;
}

void master(){
	printf("\n\nAwaiting password authentication !\n\n");
	system("sudo sleep 1 ");
	printf("Starting ztOS ssh connector client ! v2\n");
	printf("restarting SecureShell Daemon\n\n");
	system("sudo systemctl restart ssh");
	printf("Select Option ");
	printf("1)Connect ztCC, 2)Other SSH connection\n\n"); 
	int c;
	printf("Selection :");
	scanf("%d",&c);
	printf("%d",c);
	if (c == 1){
		ssh_ztccsyscnnect();
	}else if(c == 2){
		ssh_connect();
	}else{
		printf("KEY ERROR!");
	}
}

void ssh_ztccsyscnnect(){
	printf("Pinging Central Computer for data packets\n");
	system("ping -c 2 192.168.1.46");
	printf("Establishing Connection with Zerone Technologies Central Computer MARK 1 Server !\n");
	printf("Logging in as Zerone Brianstorm(zerone)\n");
	system("ssh zerone@192.168.1.46");
	printf("System Disconnected With Zerone Technologies Central Computer MARK 1 \n\n");
}

void ssh_connect(){
	printf("Enter the Username and IP address of the server\n");
	char user[256], ip[256];
	printf("user:");
	scanf("%s", user);
	printf("IP:");
	scanf("%s", ip);
	char buf[100];
	snprintf(buf,sizeof(buf),"ssh %s@%s", user, ip);
}
