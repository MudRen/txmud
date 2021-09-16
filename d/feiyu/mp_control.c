// mp_control.c

protected mapping miaopu = ([]);

mapping q_mp()
{
	return miaopu;
}

protected void allocate_miaopu()
{
	miaopu = allocate_mapping(9);

	for(int i=0;i<9;i++)
	{
		object ob;
		string file;

		file = sprintf(__DIR__"miaopu%d", (i+1));

		if(!objectp(ob = find_object(file)) && !objectp(ob = load_object(file)))
			error(sprintf("�޷����뷿�� %s.\n", file));

		miaopu += ([ ob : 0 ]);
	}
}

protected void check_miaopu()
{
	mapping tmp = ([]);

	if(!mapp(miaopu) || !sizeof(miaopu))
		return allocate_miaopu();

	foreach(object one, string who in miaopu)
	{
		if(objectp(one))
			tmp += ([ one : who ]);
	}

	miaopu = tmp;

	if(sizeof(miaopu) >= 9)
		return;

	for(int i=0;i<9;i++)
	{
		object ob;
		string file;

		file = sprintf(__DIR__"miaopu%d", (i+1));

		if(!objectp(ob = find_object(file)) && !objectp(ob = load_object(file)))
			error(sprintf("�޷����뷿�� %s.\n", file));

		if(undefinedp(miaopu[ob]))
			miaopu += ([ ob : 0 ]);
	}
}

protected void create()
{
	allocate_miaopu();
}

int valid_begin(object mp, string who)
{
	int i;
	string *worker;

	if(!mp || !who)
		return 0;

	if(!mapp(miaopu) || !sizeof(miaopu))
		allocate_miaopu();

	if( member_array(0, keys(miaopu)) != -1)
		check_miaopu();

	if(undefinedp(miaopu[mp]))
		return notify_fail("�Ƿ������\n");

	if(miaopu[mp] == who)
		return 1;

	worker = values(miaopu);

	if( (i=member_array(who, worker)) == -1 )
	{
		miaopu[mp] = who;
		return 1;
	}

	else
		return notify_fail(sprintf("���ڡ�%s���Ļû�и����أ��Ͻ�ȥ�ɡ�\n", keys(miaopu)[i]->query("short")));
}

void refresh_worker(object mp)
{
	if(!undefinedp(miaopu[0]))
		check_miaopu();

	if(undefinedp(miaopu[mp]))
		return 0;

	miaopu[mp] = 0;
}
