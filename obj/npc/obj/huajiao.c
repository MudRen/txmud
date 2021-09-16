// huajiao.c

inherit F_DBASE;
inherit F_NAME;
inherit F_MOVE;

string get_long();
string get_short();
int is_marry_ob() { return 1; }

void create()
{
	set("short",(: get_short :));

	set_name("С����", ({ "hua jiao" }) );
	set_max_encumbrance(100000000000);
	set_weight(1000000);

        set("long", (: get_long :));

	set("hide_inventory",1);
	set("no_get",1);
	set("value",1);
	set(SAFE_ENV,1);
}

string get_short()
{
	object me = this_player();

	if(!me || environment(me) == this_object())
		return "С����";
	return 0;
}

string get_long()
{
	object me = this_player(),env,*ob;
	string out;
	int n;

	if(!me || !(env = environment(me)))
		return "";

	if(env == this_object())
		return "����һ�����������Ķ���̧С���Σ��ε��ϻ�����˿����棬
��˵��ֻ����һ�����˵�С�Σ�ȴ�ǳ�����������΢΢����һ
˿���͸�����룬���Ž����н����н�������µ��������˸о�
�ǳ������ʡ�\n";


	out = "
����һ�����������Ķ���̧С����";

	if(n = sizeof(ob = all_inventory(this_object())))
		for(int i=0;i<n;i++)
			if(userp(ob[i]))
				out += sprintf("��͸������\n��Լ�ܿ���%s��������",ob[i]->name());

	return out +"��\n";
}

void init()
{
	add_action("do_enter",({"zuo","enter"}));
	add_action("do_quit",({"quit"}));
}

int do_quit()
{
	object me = this_player();

	if(!me || environment(me) != this_object())
		return 0;

	write("ý���ÿ�����һ����ס��˵�������ż��Ϳ쵽�ˣ���Ҫ�������ҿ���ô�ͱ��˽���ѽ��\n");
	return 1;
}

int do_enter(string arg)
{
	object me = this_player();

	if(!environment() || environment(me) != environment())
		return 0;

	if(!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	if(sizeof(filter_array(all_inventory(this_object()),(: userp :))))
		return notify_fail("�������Ѿ����������ˡ�\n");

	message_vision("$N���˽��ӡ�\n",me);
	me->move(this_object());
	return 1;
}

void begin_walking()
{
	call_out("walking",3);
}

void walking()
{
	tell_object(this_object(),"\nС���λλ����Ƶ���ǰ�н��ţ����治ʱ���������η��ߺ������\n");
	call_out("walking",5);
}

void stop_walking()
{
	if(find_call_out("walking"))
		remove_call_out("walking");

	tell_object(this_object(),"��ֻ����������ǰһ�ԣ�С����ͣ��������\n");
}
