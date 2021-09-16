// autoload.c
// Modified by Find.

string *autoload;

void clean_up_autoload() { seteuid(getuid());autoload = 0; }

void save_autoload()
{
	object *inv;
	int i, n;

	if(!n = sizeof(inv = filter_array(all_inventory(), (: $1->query_autoload() :))) )
		return;

	autoload = allocate(n);

	for(i=0; i<n; i++)
		autoload[i] = base_name(inv[i]);
}

void restore_autoload()
{
	int i;
	object ob;
	string file, param, err,key_master;

	if( !pointerp(autoload) ) return;

	for(i=0; i<sizeof(autoload); i++)
	{
		if( sscanf(autoload[i], "%s:%s", file, param)!=2 )
		{
			file = autoload[i];
			param = 0;
		}

		if(sscanf(file,PHOME_DIR+"%*s/%s_key",key_master)) // by Find.
		{
			if(key_master != this_object()->query("id"))
				log_file("autoload",sprintf("%s(%s)���ϴ���%s�ļ���Կ�ס�%s\n",
					this_object()->name(),this_object()->query("id"),
					key_master,ctime(time())));
		}

		if(sscanf(file,WIZ_DIR"%*s") && !wizardp(this_object()))
		{
			log_file("autoload",sprintf("%s(%s) ���ϴ���Υ��Ʒ (%s) ��û��.\n",
			this_object()->query("name"),geteuid(this_object()),file ));
			continue;
		}

		if(file_size(file+".c") <= 0)
		{
			write("������ƺ�ʧ����ʲô��Ҫ�Ķ��������֪ͨһ����ʦ��\n");
			log_file("autoload", sprintf("Fail to autoload %s of %s, error���ļ������ڡ�\n",
				file, this_object()->query("id")));
			continue;
		}

		err = catch(ob = new(file));
		if( err || !ob ) {
			write("������ƺ�ʧ����ʲô��Ҫ�Ķ��������֪ͨһ����ʦ��\n");
			log_file("autoload", sprintf("Fail to autoload %s of %s, error %s\n",
				file, this_object()->query("id"), err));
			continue;
		}

		export_uid(ob);

                if(!ob->move(this_object()))
		{
                        write("����Զ�������Ʒ����������֪ͨ��ʦ����\n");
                        this_object()->set_temp("wiznotes/"+ob->query("id"),param);
                        log_file("autoload", sprintf("*** %s(%s) fail to autoload (%s) : %s\n",
                                this_object()->name(),this_object()->query("id"),file,param,));
                        destruct(ob);
			continue;
		}
                else
		{
#ifdef WIZARD_FLAG
			if(wizardp(this_object()))
				ob->set_flag(1);
#endif
			ob->autoload(param);
		}
	}
	clean_up_autoload();		// To save memory.
}
