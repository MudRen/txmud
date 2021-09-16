#include <ansi.h>
int ask_kill();
inherit NPC;
void create()
{
        set_name("������", ({ "huo xinxin" , "xinxin" , "huo"}) );
        set("gender", "Ů��" );
        set("age",26);
        set("nickname",HIR"һ�����ؼ�Ѫ"NOR);
        set("long", "�������������Ĵ�ɱ�ֵ�ʦ��������һ�����ڽ����Ϻ������֡�\n");
        set("title",HIW"ɱ��ɽׯ--ɱ��֮��"NOR);
        set("combat_exp", 3800000);
        set("per", 30);
        set("str",100);
        set("max_force", 4000);
        set("force",4000);
        set("force_factor",200);

        set_skill("sword",300);
        set_skill("unarmed",100);
        set_skill("dodge",600);
        set_skill("parry",100);
        set_skill("force",100);
        set_skill("jieqing-sword", 280);
        set_skill("suiyu-force", 140);
        set_skill("zuiyue-strike", 120);
        set_skill("piaoyu-steps", 300);
 
        map_skill("unarmed","zuiyue-strike");
        map_skill("dodge","piaoyu-steps");
        map_skill("sword","jieqing-sword");
        map_skill("force","suiyu-force");
        map_skill("parry","jieqing-sword");

        setup();

        set("inquiry", ([
        "ɱ��ɽׯ":"ɱ��ɽׯ��������ɱ����ǰ��������֯��\n",
                "�Ĵ�ɱ��" : "�������ҵ��ĸ�ͽ�ܡ�\n", 
                "�º�ɱ��ҹ":(:ask_kill:),
]) );
        carry_object(__DIR__"obj/blackcloth")->wear();
        carry_object(__DIR__"obj/killersword")->wield();        
}

int ask_kill()
{
        object me,ob;
        me = this_player();
        if (me->query("class") != "rain" || me->query("combat_exp") < 1500000 || (int)me->query_temp("louth_huoxx") == 1)
        {
                command ("?");
                write (HIR"������������¶����һ˿ɱ����\n"NOR);
                return 1;
        }
        command ("?");
        command ("say �����ҵ�����ɱ��ɽׯʱ�õ��п�,����ô֪����?");
        command ("say ��Ȼ���Ѿ�֪����,�Ҿ��ٸ�����һЩ���ܰ�.\n");
        call_out("mimi1",5);
        return 1;
}
int mimi1()
{
        write ("\n�����������뵱�꣬����ɱ��ɽׯ�ڽ��������˲�֪�����˲�
�£������һ�������û����С�������е�ɱ��֮����\n");
        command ("sigh");
        call_out("greeting1",3);
}
int greeting1()
{
        write ("\n���������ŵ��������Դ���Ҵ�һ�ۺ���������ɱ��������
�ˣ��Ӵ�һ�겻��\n");
        call_out("greeting2",3);
}
int greeting2(object ob)
{
        write ("\n������˵������������ö��ɱ�ȥ�����ҵ��ĸ磬��������
���޻�ɱ�ֵĽ������\n");
        write ("\n����������˵������Ҫ���ܰ������æ�����ǲ��������ģ���ȥ�ɣ�\n");
        this_player()->set_temp("louth_huoxx",1);
        ob=new(__DIR__"obj/bling");
        ob->move(this_player());
}

int accept_object(object me, object ob)
{
        if(ob->query("id") == "shuangxue sword")
        {
                if (!me->query_temp("louth_xsword"))
                {
                        command ("grin");
                        command ("say ��ƭ�ң�û��ô���װɣ�\n");
                        this_object()->kill_ob(me);
                        return 1;
                }
        command ("say ��л��\n");
                command ("say ��ֻҪ֪�����ĸ罡�ھͺá�\n");
                me->delete_temp("louth_xsword");
                return 1;
        }
        return 0;
}

