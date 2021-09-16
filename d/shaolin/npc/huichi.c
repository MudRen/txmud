// huichi.c
// �ؾ�������
// by Find.

#include <ansi.h>

inherit NPC;

string ask_me(object who);
int ask_yijin(object me);
int ask_book(object who,string topic);
int ask_all(object who);

protected string *books = ({
"changquan",
"damo-sword",
"ganchan",
"jingang",
"weituo-gun",
"cibei-blade",
});

protected string all_msg;

protected void make_book_msg()
{
	if( !all_msg )
		all_msg = "";

	foreach(string tmp in books)
		all_msg += sprintf("    %s(%s)\n", to_chinese(tmp), tmp);
}

void create()
{
	set_name("�޳�", ({ "hui chi" }) );

	set("class","shaolin");
	create_family("������", 36, "����");
	set("title","�ؾ�������");

	set_auto_recover(1);

	set("gender", "����" );
	set("age", 53);
	set("long", "��λ��ɮ���������²ؾ���������\n");
	set("attitude", "peaceful");
	set("inquiry",([
	"����" : (: ask_me :),
	"jing shu" : (: ask_me :),
	"�׽" : (: ask_yijin :),
	"book" : (: ask_all :),
	WILDCARD : (: ask_book :),
]));

	set("combat_exp", 3000000);
	set("str", 67);
	set("max_kee",2500);
	set("kee",2500);
	set("max_gin",2500);
	set("gin",2500);
	set("max_sen",2500);
	set("sen",2500);
	set("force", 2000);
	set("max_force", 2000);
	set("atman", 2000);
	set("max_atman", 2000);
	set("mana", 2000);
	set("max_mana", 2000);
	set("force_factor", 300);

	set_skill("unarmed",260);
	set_skill("dodge",260);
	set_skill("parry",250);
	set_skill("force",200);
	set_skill("stick",200);
	set_skill("iron-cloth",260);
	set_skill("perception",260);
	set_skill("yiqi-force",200);
	set_skill("ganchan",250);

	map_skill("force","yiqi-force");
	map_skill("dodge","ganchan");

	make_book_msg();
	setup();

	carry_object(__DIR__"obj/cangjing_key");
	carry_object(__DIR__"obj/seng_pao")->wear();
}

int ask_yijin(object me)
{
	if(me->query("class") != "shaolin")
		return 0;

	if(!me->query("family/can_study_yijin"))
	{
		write(CYN"�޳�˵����δ�÷�����ɣ����ɲ����׽����������\n"NOR);
		return 1;
	}

	write(CYN"�޳�˵������Ȼ�����������Խ�ȥ�ˣ����ڶ����С�ݡ�\n"NOR);
	call_out("do_open",2);
	return 1;
}

void want_out()
{
	call_out("do_open",2);
}

void do_open()
{
	command("unlock door");
	command("open door");
	call_out("do_close",5);
}

void do_close()
{
	command("close door");
	command("lock door");
}

string ask_me(object who)
{
	if(!who || who->query("class") != "shaolin")
		return 0;

	return "һЩ��Ҿ��䶼������ϣ����Լ������ã����⻹��һЩ��ѧ�伮����֪��Ҫ�ı���\n";
}

int ask_book(object who,string topic)
{
	int n;
	string file;
	object book_ob;

	if(!who || !stringp(topic))
		return 0;

	if( ((n = member_array(topic,books)) == -1)
	&& ( (n = member_array(topic,map_array(books,(: to_chinese :)))) == -1))
		return 0;

	file = sprintf(__DIR__"obj/%s_book",books[n]);
	if(file_size(file+".c") <= 0 || !book_ob = new(file))
		return 0;

	message_vision(sprintf("$N������ó�һ��%s������$n��\n",book_ob->name()),
		this_object(),who);
	book_ob->move(who);

	command("say ��ɷ��ͣ���ѧ�伮����Я���ؾ���\n");
	return 1;
}

int accept_object(object who,object ob)
{
	if(!who || !ob)
		return 0;

	if(ob->is_shaolin_book())
	{
		call_out("destruct_book",1);
		return 1;
	}
	else
		return 0;
}

void destruct_book()
{
	int i,n;
	object *inv;

	inv = all_inventory(this_object());
	if(!n = sizeof(inv))
		return;

	for(i=0;i<n;i++)
		if(inv[i]->is_shaolin_book())
			destruct(inv[i]);
}

int ask_all(object who)
{
	if(who->query("family/family_name") != "������")
		return 0;

	tell_object(who, sprintf("\n�޳�˵��������ֻ����Щ�书�������鼮��\n%s\n", all_msg));
	return 1;
}
