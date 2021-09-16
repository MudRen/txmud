// huashan master-lh.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me(object who);
string ask_feng(object who);
string ask_jindi(object who);

void create()
{
    set_name("�����", ({ "master ling", "master"}) );

        set("nickname", HIG"ƽ����"NOR);

        set("class","huashan");
        set("gender", "����" );
        set("age", 28);
        set("str", 50);
        set("cor", 30);
        set("int", 60);
        set("per", 30);
        set("con", 30);
        set("kar", 50);

        set("max_force", 5000);
        set("force", 5000);
        set("force_factor", 120);

        set("max_gin",3000);
        set("max_kee",3000);
        set("max_sen",3000);

        set("long",@LONG
���������������Ⱥ��С�����Ĺ¶������
�䲻̫�󣬰���ʦ��ȴ�����磬�ǻ�ɽ�ɵ�
����ӡ�ֻ�������Բ����ϲ�������
���������Ⱥ�״�����ϼ�񹦣��书ȴҲ��
�������г���δ�ĸ��֡�
LONG );

        create_family("��ɽ��", 4, "��ʦ��");
        set("combat_exp", 1000000);
        set("score", 300000);

        set("chat_chance", 1);
        set("chat_msg", ({
        "�ȣ�Ҳ��֪ʦ������ϼ����ϰ������ˡ�\n",
        "�ȣ��Դӹ��������£��Ҷ�������û��һ�ξ��ˡ�\n",
        "�ԾƵ��裬�������Ρ�\n",
}) );

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
}) );

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
                "��ɽ��" : "��ɽ���Ż���ʱ���Ҵ��ƣ����к�ָ�̣�",
                "��ʦ"   : "��ɽ�����ڹ��ͽ����������յ����������ԡ�",
                "apprentice": "��ɽ�����ڹ��ͽ����������յ����������ԡ�",
                "name": "�ұ��ǻ�ɽ�ɵ�����壬���ڴ��ƻ�ɽ�ɡ�",
                "����" : (: ask_me :),
                "������" : (: ask_feng :),
                "����" : (: ask_jindi :),
]) );

        setup();
        // carry_object(__DIR__"obj/cloth")->wear();
}
   
void attempt_apprentice(object ob)
{
        if(ob->query("gender") != "����")
        { command("say ��ȥ��Сʦ��ȥ�ɡ�"); return; }

        if(ob->query("int") < 25)
        {
                command("say �����书��Ҫ���õ����ԣ������������ɡ�\n" +
                RANK_D->query_respect(ob) + "�����Ժ��񣬿�...��������ɵ��İɣ�");
                return;
        }

        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huashan");
}

string ask_me(object who)
{
        if(!who->is_apprentice_of(this_object()))
                return 0;
 
        if( (who->query_skill("dodge",1) < 160)
        || (who->query_skill("zixia-force",1) < 160) )
                return "�����书ѭ�򽥽����ȴ�û�����˵��";

        return "ʦ�����ٲ���������΢���չؾ�����ϼ�ؼ���ֻ��ÿ��\n\t��������Ϣ�������ʱȥ�ݼ��ֽ̡�";
}

string ask_feng(object who)
{
        if(who->query("class") != "huashan")
                return 0;

        if(who->query_temp("asked_lh_about_feng"))
                return "���Ǻ���˵���ˣ����ú�������������������ʲô��";

        if( (who->query_skill("dodge",1) < 160)
        || (who->query_skill("zixia-force",1) < 160) )
                return "�������ɵ�ǰ�����ˣ���˵�������Ӳ����ˡ�";

        who->set_temp("asked_lh_about_feng",1);
        return "�������ɵ�ǰ�����ˣ��������Ӳ����ˣ������˼ҵ�����֮��\n
˭Ҳ��֪���������д��������˼Ҿ������ڻ�ɽ��������ϼ��
ס���Ǹ�СŮ������˵�����һ�ɽ����ͽ������˵�����ɴ���
ԨԴ������С���ڻ�ɽ�Ĵ��ε��������ȥ��������������";
}

string ask_jindi(object who)
{
        if(who->query("class") != "huashan")
                return 0;

        if(who->query_temp("asked_jindi_enter"))
                return "���Ǻ���˵���ˣ����ú�������������������ʲô��";

        if( (who->query("combat_exp",1) < 2000000)
        || (who->query_skill("zixia-force",1) < 200) )
                return "�㲻�ú����������������ʲô��";

        who->set_temp("asked_jindi_enter",1);
        return "�������ɵĵĽ��أ��������ź�����ɵĵ���֮�⣬��������
һ�ɲ�����������˵�����ڽ������淢��һֻ�������
��Ϊ�˽�������������������������Ϊ���Ե�ʰɡ����Ȼ��
����ȥ�����Ҿ͸����㣺��������ðݼ�����ʦү��Ĺ�����
����������Ҫ�Ĵ��ҹ䡣";
}

