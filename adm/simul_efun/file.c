// file.c
// Modified by Find.

nomask void cat(string file)
{
// modified by Find.�޴�İ�ȫ©������� simul_efun
// ��ȫ��Խ��valid_read �ļ�⣬��˽������޸ġ�
	object ob;

	if(!ob = find_object(MASTER_OB))
		return;

	if(this_player(1) && file_name(previous_object()) != "/adm/daemons/logind")
	{
		if(!ob->valid_read(file,this_player(1),"read_file"))
			return;
		else
		{
		write(read_file(file));
		return;
		}
	}
	else if(ob->valid_read(file,previous_object(),"read_file"))
		write(read_file(file));
	else return;
// end.
}

nomask void log_file(string file, string text)
{
	write_file(LOG_DIR + file, text);
}

nomask void sys_log(string file,string text)
{
	write_file("/syslog/"+file,text);
}

// ��ȫ©��,��������������κ����
// �����κ�Ŀ¼,ͬʱ�� SIMUL_EFUN ��
// euid ���ó� ROOT_UID.
// Modified it by Find.
nomask void assure_file(string file)
{
	string path, *dir;
	int i;

	if( file_size(file)!=-1 ) return;

	seteuid(ROOT_UID);
	dir = explode(file, "/");
	dir = dir[0..sizeof(dir)-2];
	path = "/";
	for(i=0; i<sizeof(dir); i++)
	{
		path += dir[i];
		mkdir(path);
		path += "/";
	}
	seteuid(getuid());	// By Find.
}

nomask string base_name(object ob)
{
	string file;

	if( sscanf(file_name(ob), "%s#%*d", file)==2 )
		return file;
	else
		return file_name(ob);
}