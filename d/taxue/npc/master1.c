// master1.c
// by dicky

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

string ask_yujian();
string ask_chugu();

void create()
{
        set_name("̤ѩ�ݲ�", ({ "taxue rongbo", "rongbo"}) );
        set("class","taxue");
        create_family("̤ѩɽׯ", 1, "����");

        set("title",HIW"�н���ѩ"NOR);	
        set("long", 
                "����̤ѩɽׯ��ǰ����ʦ���ųơ��н���ѩ����\n"
                "����ͷ������ֱ�����أ���ü���룬������Ͷ�������ס�ˡ�\n"
                "���뷢��Ȼ����δȫ�ף�ֻ�ǲ�֪�ж����겻�꣬����Ұ��һ��ë���׵��������ˡ�\n");
        set("gender", "����" );
        set("age", 60);
        set("attitude", "peaceful");
        set("str",40);
        set("int",30);
        set("con",30);
        set("dex",30);
        set("per", 25);
        
        set("max_kee", 9999);
        set("max_gin", 9999);
        set("max_force", 9999);
        set("max_atman", 9999);
        set("max_sen", 9999);
        set("max_mana", 9999);
        set("force_factor", 500);
        set("combat_exp", 30000000);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("unarmed", 300);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("literate", 300);
        set_skill("xueli-steps", 300);
        set_skill("taxue-force", 300);
        set_skill("fenghui-sword", 300);
        set_skill("chuanyun-zhang", 300);

        map_skill("sword", "fenghui-sword");
        map_skill("parry", "fenghui-sword");
        map_skill("unarmed", "chuanyun-zhang");
        map_skill("dodge", "xueli-steps");
        map_skill("force", "taxue-force");

        set("inquiry", ([
                "����": (: ask_chugu :),
                "chugu": (: ask_chugu :),
                "Ԧ����": (: ask_yujian :),
                "yujian": (: ask_yujian :),
                "name": "���Ҳн���ѩ�ͺ��ˡ�",
                "here": "������̤ѩɽׯ����������ܶ���ţë�������ܲ�����ȫ�ˡ�",
                "̤ѩ�ݲ�": "������ʲô����",
                "�н���ѩ": "�Ҿ��ǰ���������ʲô����",
                "̤ѩɽׯ": "�������̤ѩɽׯ��̤ѩ�޺��Ǹ�С������������������ģ�������������ܲ�����ȫ�ˡ�",
        ]));

        setup();

        carry_object(ARMOR_DIR"cloth")->wear();
        carry_object(__DIR__"obj/zhujian")->wield();
}

void attempt_apprentice(object ob)
{
	if(ob->query("class") != "taxue")
		return;

	if(ob->query_skill("taxue-force",1) < 300)
	{
		command("say ���̤ѩ�񹦻�򲻹�����ȥ������˵�ɡ�");
		return;
        }

	if(ob->query_skill("force",1) < 300)
	{
		command("say ��Ļ����ڹ���򲻹�����ȥ������˵�ɡ�");
		return;
        }

	if(ob->query_skill("fenghui-sword",1) < 300)
	{
		command("say ��ķ��ѩ�轣ѧ�û�򲻹�����ȥ������˵�ɡ�");
		return;
        }

	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
	command("recruit " + ob->query("id") );
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "taxue");
	ob->set("title",HIW"�н���ѩ�²�����"NOR);
        return 1;
}

string ask_yujian()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "�Ҹ�����ɣ���λ"+ob->name()+"��Ԧ��������һ���ϳ˵Ľ���Ŷ��";

	if(ob->query("family/master_id") != "taxue rongbo")
        return "�����Ԧ�������֮����ƾ�Լ���ս������һʱ��������ᡣ";

        if(ob->query("taxue/yujian_pass"))
        return "�㲻��ѧ����Ԧ����ô����ȥ�ټ�ǿ��ϰ�ɣ�";

	ob->set("taxue/yujian_pass",1);
        command("smile");
	command("say ��Ȼ����ô�ù������Ҿͽ�����ôʹ��Ԧ�����ɣ�");
	message_vision (HIG"\n\n̤ѩ�ݲ���$N�Ķ��ߵ���˵�˼��䣬$N���ĵ�����̤ѩ�ݲ���ָ�������Ԧ�����ľ������ڡ�\n\n"NOR, ob);
	return HIR"��ϲ�㣬������ѧ����Ԧ������"NOR;
}

string ask_chugu()
{
        object ob;
        ob = this_player();

        if(ob->query("class")!="taxue")
        return "����������������ô���ľ���ô��ȥ�ɣ��Ͳ����鷳�Ϸ��ˣ�";

        if(!ob->query("taxue/yujian_pass"))
        return "û��ѧ��Ԧ���������ȥ���㻹�ǵ�ѧ�������ߣ���ó�ȥ�������ۣ�";
	message_vision(HIC"\n\nͻȻ$N��̤ѩ�ݲ�����˦�˳�ȥ������$N�о��йɾ޴����������$P��\n$Næ�����ڹ��������������������Ԧ������������ɽ�·��˹�ȥ��\n\n"NOR,ob);
	ob->start_busy(2);
	ob->move("/d/taxue/shanya-s");
	tell_room(environment(ob), ob->name() + "ͻȻ��ɽ���������������\n", ({ ob }));
	return "���Ϸ������һ�̺��ˣ�";
}