// huashan yello-girl.c

#include <ansi.h>
inherit NPC;

string ask_feng(object who);

void create()
{
	set_name("������Ů", ({ "yellow girl" }) );
	set("title", HIY"��������"NOR);
	set("gender", "Ů��" );

	set("age", 16);
	set("str", 20);
	set("per", 30);

	set("max_gin",3000);
	set("max_kee",3000);
	set("max_sen",3000);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",200);

	set("long", @LONG
������һϮ�׻�ɫ�ĳ�ȹ��Ʈ�ݵĳ���
��һ����˿��ϵס��ü������һ����
���������ڻƻ�ʱ�����︧һ�ѹ��١�
LONG
);
	set("combat_exp", 500000);
	set("attitude", "friendly");
        
        set_skill("unarmed", 160);
	set_skill("parry", 160);
	set_skill("dodge", 160);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("huashan-sword", 180);
        set_skill("literate", 160);
        set_skill("zixia-force", 180);
        set_skill("lingyun-steps", 160);
        set_skill("fuyunshou", 160);
        map_skill("unarmed", "fuyunshou");
        map_skill("sword", "huashan-sword");
        map_skill("force", "zixia-force");
        map_skill("dodge", "lingyun-steps");

        set("inquiry", ([
              "��ɽ":"��ɽ������Χ�����ﶼ�ǻ�ɽ��",
              "��ɽ��" : "�����Ұɣ���Զ�ˡ�",
              "������": (: ask_feng :),
              //"������" : (: feng_str :),
]) );

/*
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yujian" :),
		(: perform_action, "sword.dang" :),
		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );
*/

	setup();
	
	carry_object(__DIR__"obj/erskirt")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

string ask_feng(object who)
{
	if(who->query_temp("asked_yg_about_feng"))
		return "���Ƕ�����˵��ѽ������ժ�������㶼���ɣ�������";

	if(!who->query_temp("asked_lh_about_feng"))
		return 0;

	who->delete_temp("asked_lh_about_feng");
	who->set_temp("asked_yg_about_feng",1);
	return "����ǰ�����ӵ�ʱ���һ�û�����ǣ�����ô��֪����������
���£�������ϼ�����������ɽ�ҿ��Ǻö�������Ҫ���ܰ�
��ժһ�ţ��Ҿ͸�����һ����ֵ����顣��������Щ������
�������ڶ������ġ�";
}

int accept_object(object who, object ob)
{
	if(base_name(ob) != "/d/huashan_zx/obj/tao")
		return 0;

	if(!who->query_temp("asked_yg_about_feng"))
	{
		write("������Ů˵��������ô֪����ϲ��������ѽ��лл����\n");
		return 1;
	}

	who->delete_temp("asked_yg_about_feng");
	write("������Ů������˵��лл���������ϴ�ȥ����˼�����棬վ��������
    �������������¹⿴�������Ϻ����и�ɽ������������֦Ҳ����
    ����ȥ���ҵ��Ṧ���У��ҿ��ǲ��ң�������\n");
	return 1;
}
