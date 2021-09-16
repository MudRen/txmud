// huashan master-yue.c
// 11:00 - 15:00 ѧϰʱ��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_ziqi(object who);

void create()
{
	set_name("����Ⱥ", ({ "master yue" }) );
	set("nickname",HIW"��ɽ����"NOR);

	set("class","huashan");

	set("gender", "����" );

	set("age", 54);
	set("str", 80);
	set("cor", 30);
	set("int", 60);
	set("per", 30);
	set("con", 60);
	set("kar", 50);

	set("max_force", 20000);
	set("force", 20000);
	set("force_factor", 400);

	set("max_gin",10000);
	set("max_kee",10000);
	set("max_sen",10000);

	set("long",@LONG
����Ⱥ�������εĻ�ɽ���ţ������ܸɣ����
���ߡ�Ϊ�����¼����ļơ�Ȣ�����ŵ�Ů����
�������ϻ�ɽ����Ҳ�Ǽ��кô�����Ϊ��ɽ��
׳��չ���ǲ���������
LONG );

	create_family("��ɽ��", 3, "����");
	set("combat_exp", 7000000);

	set_skill("unarmed", 280);
	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("sword", 300);
	set_skill("force", 300);
	set_skill("huashan-sword", 300);
	set_skill("literate", 300);
	set_skill("zixia-force", 300);
	set_skill("lingyun-steps", 280);
	set_skill("fuyunshou", 280);

	map_skill("unarmed", "fuyunshou");
	map_skill("sword", "huashan-sword");
	map_skill("force", "zixia-force");
	map_skill("dodge", "lingyun-steps");

	set("inquiry", ([
		"ziqi": (: ask_ziqi :),
		"��������": (: ask_ziqi :),
]) );

	setup();
	carry_object(__DIR__"obj/hs_cloth")->wear();
}
       
void attempt_apprentice(object ob)
{
	if(ob->query("class") != "huashan")
		return;

	if( ob->query("int") < 30 )
	{
		command("say ��ϰ�����ķ�������Ҫ��֮�Ժ������������Ҫ���õ����ԣ�");
		return;
	}

	if( ob->query_skill("dugu-sword",1) )
	{
		command("say ��Ȼѧ���˷�ʦ��ġ����¾Ž������������С����ѧҲ�ա�");
		command("heng");
		return;
	}

	if( ob->query_skill("zixia-force",1) < 160 )
	{
		command("say �����ϼ�񹦻��̫����˽��ޡ�����");
		return;
	}

	command("smile");
	command("say �ܺã���С���ɽ���ɡ�������ȴ��֪�����ڹ������ǲ����\n            �����������������书���衣������ѧ�������պ���������鹡�\n");
	command("recruit " + ob->query("id") );
	ob->save();
	command("say �Ժ�ÿ�ա���䡹����������书������ʱ��ΪʦҪ������ϼ�ķ���\n\t���������ڹ��ܸ���һ��¥��");
}
    
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "huashan");
}

int prevent_learn(object who,string skill)
{
	int n = query_time();

	if( (n < 660) || (n > 900) )
		return notify_fail("����Ⱥ˵������Ҫ����书�͡���䡹����������ʱ��Ҫ�������ң�\n");

	if(who->query_skill("dugu-sword",1))
		return notify_fail("say ��Ȼѧ���˷�ʦ��ġ����¾Ž������������С����ѧҲ�ա�");

	return 1;
}

string ask_ziqi(object who)
{
	if(!who->is_apprentice_of(this_object()))
		return 0;

	if(who->query("family/master_yue_teach"))
		return "������ϰ����ϼ�񹦡�����������������Ч����Խ��Խ�ߵġ�";

	if(who->query_skill("zixia-force",1) < 150)
		return "��ġ���ϼ�񹦡������������޷���ϰ��������������";

	message_vision("\n$N���˵�ͷ������$n��������һ��ʲô������������\n$n��¶ϲɫ˵�����ǡ��������������ˣ���лʦ����\n\n",this_object(),who);
	who->set("family/master_yue_teach",1);
	return "���п���������ɽ��������Ч�����Ժ�Ҫ��ѧ��������ϼ�񹦡���\nЧ���᲻����ߡ�����";
}

