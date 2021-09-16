// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_book();

void create()
{
	set_name("̤ѩĪ��", ({ "taxue mocong","mocong", "man" }));
	set("class","taxue");
        create_family("̤ѩɽׯ", 2, "����");
	set("gender", "����");
	set("age", 36);  
	set("long", "����ׯ��̤ѩ��Զ���������ӣ���������������΢������������������\n");
	set("book1_count",3);
	set("book2_count",3);
	set("book3_count",3);
	
	set("combat_exp", 400000);

        set("max_kee",2200);
        set("max_gin",2200);
        set("max_sen",2200);
        set("max_force", 2800);
        set("max_atman", 2800);
        set("max_mana", 2800);
        set("force_factor", 100);

        set_skill("literate",150);
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",150);
        set_skill("sword",150);	     
 
	set("inquiry",([
           "ѧϰ" : (: ask_book :),
           "����" : (: ask_book :),
	]));

	setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_book()
{
	object me;
	me=this_player();

	if(me->query("class") != "taxue")
		 return "��ֻ�ܸ����ŵ��ӣ��㻹�����������İ취�ɣ�";

	if(me->query_skill("literate", 1) > 120 )
		 return "���ѧʶ�Ѿ����ߵ��ˣ����ò����Ǳ��顣\n";

	if(me->query_skill("literate", 1) < 30 )
	{

	if(me->query_temp("taxue/askbook"))
		 return "��ղŲ����ù���ô����ô�������ˣ�";

	if (query("book1_count") < 1) 
		return "Ŀǰ�鼮�Ѿ����ù��ˣ��Ȼ������ɣ�";

	command("smile");
	me->set_temp("taxue/askbook",1);
        add("book1_count", -1);

	message_vision(
                HIW"\n̤ѩĪ�Ҹ�$Nһ�����־���\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book")->move(me);
	return "������ˣ��ǵ�һ��ҪŬ��ѧϰѽ!\n";
	}

	if(me->query_skill("literate", 1) < 70 )
	{
	if(me->query_temp("taxue/askbook1"))
		 return "��ղŲ����ù���ô����ô�������ˣ�";

	if (query("book2_count") < 1) 
		return "Ŀǰ�鼮�Ѿ����ù��ˣ��Ȼ������ɣ�";

	command("smile");
	me->set_temp("taxue/askbook1",1);
        add("book2_count", -1);

	message_vision(
                HIG"\n̤ѩĪ�Ҹ�$Nһ���������\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book2")->move(me);
	return "������ˣ��ǵ�һ��ҪŬ��ѧϰѽ!\n";
	}

	if(me->query_temp("taxue/askbook2"))
		 return "��ղŲ����ù���ô����ô�������ˣ�";

	if (query("book3_count") < 1) 
		return "Ŀǰ�鼮�Ѿ����ù��ˣ��Ȼ������ɣ�";

	command("smile");
	me->set_temp("taxue/askbook2",1);
        add("book3_count", -1);

	message_vision(
                HIW"\n̤ѩĪ�Ҹ�$Nһ�����ӱ�����\n"NOR,
                this_player(), this_object() );
	new("/d/taxue/obj/lite-book3")->move(me);
	return "������ˣ��ǵ�һ��ҪŬ��ѧϰѽ!\n";
}