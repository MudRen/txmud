// ph_girl.c

inherit NPC;

string ask_me(object who);
private int working;

void create()
{
	set_name("��ҩŮ��", ({ "pharmacy girl" }) );
	set("gender", "Ů��" );
	set("age", 20);

	set(NO_KILL, 1);

	set("inquiry",([
	"������" : (: ask_me :),
]));

	set("long", "������Ц�����ģ�һ���������ǵ����ӡ�\n");
	set("combat_exp", 100);
	set("per", 30);
	set("attitude", "friendly");
	setup();
	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_me(object who)
{
	string *get;
	object ob1,ob2,ob3,ob4;

	if(working)
		return "��æ���أ���һ����ɡ�";

	if( (who->query("quest/rain_quest/name") == "������")
	&& arrayp(get = who->query("quest/rain_quest/geted"))
	&& (sizeof(get) >= 4) )
	{
		if(!objectp(ob1 = present("lian zi",who)))
			return "�������Ӷ�û�У�û�����ư�������";
		if(!objectp(ob2 = present("jinyin hua",who)))
			return "������������û�У�û�����ư�������";
		if(!objectp(ob3 = present("baishi guo",who)))
			return "������ʵ����û�У�û�����ư�������";
		if(!objectp(ob4 = present("buyun cao",who)))
			return "�������Ʋݶ�û�У�û�����ư�������";

		working = 1;
		destruct(ob1);
		destruct(ob2);
		destruct(ob3);
		destruct(ob4);
		message_vision("$N��$n���ϵ�ԭ�Ͻ��˹�ȥ��\n",this_object(),who);
		call_out("do_working",4,who,0);
		return "�ã����һ�£���ͺá�\n";
	}
}

void do_working(object who,int n)
{
	object ob;

	remove_call_out("do_working");

	if(!who)
	{
		working = 0;
		return;
	}

	switch (n)
	{
		case 0:
			message_vision("$N��ԭ�϶�Ͷ�ڹ������ˮ�������˻�\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 1:
			message_vision("$Nʹ�����ŷ��䣬���µĻ�Խ��Խ����\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 2:
			message_vision("�����ˮ����ཹ�ཡ�������������������ð����������\n\n",this_object());
			call_out("do_working",6,who,++n);
			break;
		case 3:
			message_vision("�����ˮԽ��Խ�٣������ı�����غ�ɫ��\n\n",this_object());
			call_out("do_working",8,who,++n);
			break;
		default:
			message_vision("$N˵������������\n˵�����˻𽫹�������������\n\n",this_object());
			if(environment(who) != environment())
			{
				message_vision(sprintf("$N���ҿ��˿�%sû�ڣ�˳�ְѰ��õ��������˵��ϡ�\n\n",
					who->name()),this_object());
				working = 0;
				return;
			}
			ob = new(__DIR__"obj/baiyun_tang");
			ob->move(this_object());
			command(sprintf("give baiyun tang to %s",who->query("id")));
			working = 0;
	}
}
