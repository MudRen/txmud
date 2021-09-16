// dizi4
// by dicky

#include <ansi.h>
inherit NPC;

string ask_huju();

void create()
{
	set_name("̤ѩ�ɻ�", ({ "taxue feihu","feihu", "man" }));
	set("class","taxue");
        create_family("̤ѩɽׯ", 2, "����");
	set("gender", "����");
	set("age", 36);  
	set("long", "����ׯ��̤ѩ��Զ��������ӣ����û����������ǳ���ʵ��\n");
	set("combat_exp", 400000);
	set("huju_count",6);

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
           "����" : (: ask_huju :),
           "huju" : (: ask_huju :),
	]));

	setup();

        carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_huju()
{
	object me;
	me=this_player();

	if(me->query("class") != "taxue")
		 return "����ֻ�ܸ����ŵ��ӣ��㻹�����������İ취�ɣ�";
	if(me->query_temp("taxue/askhuju"))
		 return "��ղŲ����ù���ô����ô�������ˣ�";
	if(me->query_skill("force", 1) < 50 )
		 return "��Ĺ��򻹲�����죬���߸���Ҳ���˷ѣ��������������ĵ����ðɡ�\n";
	if (query("huju_count") < 1) return "Ŀǰ�����Ѿ����ù��ˣ��Ȼ��";

	command("smile");

	me->set_temp("taxue/askhuju",1);

        new(__DIR__"obj/shoes")->move(me);
        new(__DIR__"obj/armor")->move(me);
        new(__DIR__"obj/hands")->move(me);
        new(__DIR__"obj/head")->move(me);
        new(__DIR__"obj/pifeng")->move(me);
        new(__DIR__"obj/waist")->move(me);
        new(__DIR__"obj/wrists")->move(me);

        add("huju_count", -1);

        message_vision("$N���һ��̤ѩɽׯ���ߡ�\n",this_player());
        return "��������һ�׻��ߣ���Ч����������ȥ����ɡ�";
}