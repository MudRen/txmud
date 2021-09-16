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
        set_name("唐铁嘴", ({"tang tiezui"}));
        set("long", "这是一位相貌古怪的中年男子，不过确是
这一带的名人，据说能知上下五百年，还
装着一肚子的笑话，所以不管大人小孩都
很喜欢他。
");
        set("gender","男性");

        set("age",44);
        set("con",20);
        set("str",20);

	set("inquiry",([
	"笑话" : "想听笑话吗？我这有的是，一个二两银子。\n",
]));

        set("combat_exp",100);
	restore();
        setup();
        carry_object(ARMOR_DIR"cloth")->wear();
}

int accept_object(object who, object ob)
{
	if(!is_money(ob) || (ob->value() < 200) )
		return notify_fail("唐铁嘴摇摇头说道：每个笑话现银二两，亲朋好友，概不赊欠。\n");

	write("唐铁嘴说道：“好！您想听(listen)哪段？可以先看(list)一下再告诉我。”\n");
	who->set_temp("tangtiezui/payed",1);
	return 1;
}

int do_listen(string arg)
{
	int n;
	object me = this_player();

	if(!me->query_temp("tangtiezui/payed"))
		return notify_fail("唐铁嘴摇摇头说道：每个笑话现银二两，亲朋好友，概不赊欠，没钱靠边站。\n");

	if(!arg || arg == "" || !(n=atoi(arg)))
		return notify_fail("唐铁嘴挤了挤小眼睛说道：“你要听哪段？”\n");

	if( (n<1) || (n>sizeof(jokes)) )
		return notify_fail("唐铁嘴挤了挤小眼睛说道：“没你点的这段，看看清楚再说。”\n");

	tell_object(me,sprintf("唐铁嘴挤了挤小眼睛说了起来：\n\n%s\n",jokes[--n]));
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
		write("取消输入。\n");
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
		return notify_fail("唐铁嘴摇摇头说道：每个笑话现银二两，没钱别瞎打听。\n");

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
