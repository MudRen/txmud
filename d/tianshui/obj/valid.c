// valid.c
// ��������Ŀ��ƺ�����
// find.

private int valid_sum = 1;

nomask int valid()
{
	string *fs =({ __DIR__"jinghong_sword",__DIR__"qiao",__DIR__"sword_and_qiao"});

	foreach(string f in fs)
	{
		object obj;
		int all;

		obj = find_object(f);
		if(!obj)
			obj = load_object(f);
		if(!obj)
			return 0;
		all = sizeof(filter_array(children(f), (: clonep :)));
		all += CTLOB_D->query_save_num(f);
		if(valid_sum <= all)
			return 0;
	}

	return 1;
}
