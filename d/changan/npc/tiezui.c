// tiezui.c
// by Find

inherit NPC;
inherit F_SAVE;

string query_save_file(){return __DIR__"jokes";}
void talk_joke(object me);
void get_joke(string str);
string *jokes = ({});

void create()
{
        set_name("������", ({"tang tiezui"}));
        set("long", "����һλ��ò�Źֵ��������ӣ�����ȷ��
��һ�������ˣ���˵��֪��������꣬��
װ��һ���ӵ�Ц�������Բ��ܴ���С����
��ϲ������
");
        set("gender","����");

        set("age",44);
        set("con",20);
        set("str",20);

	set("inquiry",([
	"Ц��" : "����Ц���������е��ǣ�һ���������ӡ�\n",
]));

        set("combat_exp",100);
	restore();
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_object(object who, object ob)
{
	if(!is_money(ob) || (ob->value() < 200) )
		return notify_fail("������ҡҡͷ˵����ÿ��Ц������������������ѣ��Ų���Ƿ��\n");

	write("������˵�������ã�������(listen)�ĶΣ������ȿ�(list)һ���ٸ����ҡ���\n");
	who->set_temp("tangtiezui/payed",1);
	return 1;
}

int do_listen(string arg)
{
	int n;
	object me = this_player();

	if(!me->query_temp("tangtiezui/payed"))
		return notify_fail("������ҡҡͷ˵����ÿ��Ц������������������ѣ��Ų���Ƿ��ûǮ����վ��\n");

	if(!arg || arg == "" || !(n=atoi(arg)))
		return notify_fail("�����켷�˼�С�۾�˵��������Ҫ���ĶΣ���\n");

	if( (n<1) || (n>sizeof(jokes)) )
		return notify_fail("�����켷�˼�С�۾�˵������û������Σ����������˵����\n");

	tell_object(me,sprintf("�����켷�˼�С�۾�˵��������\n\n%s\n",jokes[--n]));
	me->delete_temp("tangtiezui/payed");
	return 1;
}

void init()
{
	add_action("do_addjoke","addjoke");
	add_action("do_list","list");
	add_action("do_listen","listen");
}

int do_addjoke(string file)
{
	object me = this_player();

	if(wiz_level(me) < wiz_level("(arch)"))
		return 0;
	me->edit( (: get_joke :) );
	return 1;
}

void get_joke(string str)
{
	if(!str || str == "")
	{
		write("ȡ�����롣\n");
		return;
	}

	jokes += ({ str });
	save();
	write("ok.\n");
}

int do_list()
{
	object me = this_player();
	string output = "",*titles;
	int bk,n,l;

	if(!me->query_temp("tangtiezui/payed"))
		return notify_fail("������ҡҡͷ˵����ÿ��Ц������������ûǮ��Ϲ������\n");

	titles = map_array(jokes,(: explode($1,"\n")[0] :));
	titles -= ({""});

	n = sizeof(titles);
	for(int i=0;i<n;i++)
		if(strlen(titles[i]) > l)
			l = strlen(titles[i]);

	bk = to_int(85/(l+4));
	l++;

	for(int i=0;i<n;i++)
		output += sprintf("%-3d%-"+(string)l+"s%s",(i+1),titles[i],(i%bk==(bk-1))?"\n":"");

	me->start_more(output+"\n\n");
	return 1;
}
