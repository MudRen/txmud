//old_lama.c �ø»�𣬲����������Ǹ������ô��������
#include <ansi.h>
inherit NPC;
int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
        set_name("������", ({ "old lama","lama"}) );
        set("nickname", "��������");
        set("gender", "����" );
        set("age", 57);
        set("str", 13);
        set("cor", 10);
        set("cps", 50);
        set("int", 66);
        set("per", 18);
        set("con", 54);
        set("spi", 30);
        set("kar", 25);
        set("long","һ��������˥������Ѿ�û�����ͷ�ˡ�\n");
        set("combat_exp", 25000);
        set("attitude", "peaceful");
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_force", 4500);
        set("force", 9000);
        set("force_factor", 0);
        set("max_mana", 800);
        set("max_kee",2500);
        set("mana", 800);
        set("inquiry",([
        "������":(:ask_me:),
]));
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
        carry_object(__DIR__"obj/zang-blade")->wield();
}
int ask_me()
{
        object ob=this_player();
        object me=this_object();
        if(is_fighting())
        return 0;
        else if (!(int)ob->query_temp("mark/���ϰ�"))
        {
        say(CYN"������˵���������������������޴˹�����\n"NOR);
        return 1;
        }
        else
        {
        me->set_name("�ø»��",({"jiga huofo","huofo"}));
        me->set("nickname",HIR"�������"NOR);
        me->set("long","���·��ɼø»�����ڸ��֡�\n");
        me->set("combat_exp",2500000);
        me->set_skill("blade", 250);
        me->set_skill("unarmed",250);
        me->set_skill("parry", 250);
        me->set_skill("dodge", 250);
        me->set_skill("force", 250);
//        me->set_skill("fire-blade", 250);
//        me->set_skill("dashouyin", 250);
//        me->set_skill("jimie-steps", 250);
//        me->set_skill("mizong-xinfa", 250);
//        me->map_skills("blade","fire-blade");
//        me->map_skills("unarmed","dashouyin");
//        me->map_skills("parry","fire-blade");
//        me->map_skills("dodge","jimie-steps");
//        me->map_skills("force","mizong-xinfa");
        me->set("str",80);
        me->set("force-factor",120);
        say(HIC"�������Ȼ���ݶ�����ȫ����һ�ִ���ֵķ緶��\n"NOR);
        say(CYN"������˵�������ľ��Ǽø¡�\n"NOR);
        say(CYN"�ø»��˵������Ȼ�������´��򣬾������˽�˹���ʩ������аɡ�\n"NOR);
        say(CYN"�ø»��˵�������ǵ㵽Ϊֹ��\n"NOR);
        return 1;
        }
}
int accept_fight(object ob)
{
        object me=this_object();
        int qi_now=(int)me->query("kee");
        int qi_max=(int)me->query("max_kee");
        if (qi_now+100>qi_max)
        {
        say(CYN"�ø»��˵�����ðɣ����Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n"NOR);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        return 1;
        }
        else
        {
        say(CYN"�ø»��˵�����������е��ۣ����ȵȻ����\n"NOR);
        return 0;
        }
}
int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_kee");
        his_max_qi = (int)ob->query("max_kee");
        if (me->is_fighting()) 
        {
          call_out("checking",2, me, ob);
          return 1;
        }
        if ( !present(ob, environment()) ) return 1; 
        if (( (int)me->query("kee")/my_max_qi) <= 10 ) 
        {
          say(CYN"�ø»��˵��ʩ�����ֹ�Ȼ����������������Ȿ���浶������ȥ�ɡ�\n"NOR);
          obj=new(__DIR__"obj/fire_book1"); 
          if (!objectp(obj))
          obj=new(__DIR__"obj/fire_book2");
          obj->move(ob);
          message_vision("$N����$nһ���顣\n", me, ob);
          ob->delete_temp("mark/���ϰ�");
          me->set_name("������",({"old lama","lama"}));
          me->set("nickname","��������");
          me->set("long","һ��������˥������Ѿ�û�����ͷ�ˡ�\n");
          me->set("combat_exp",25000);
          me->delete_skill("blade", 250);
          me->delete_skill("unarmed",250);
          me->delete_skill("parry", 250);
          me->delete_skill("dodge", 250);
          me->delete_skill("force", 250);
//        me->delete_skill("fire-blade", 250);
//        me->delete_skill("dashouyin", 250);
//        me->delete_skill("jimie-steps", 250);
//        me->delete_skill("mizong-xinfa", 250);
          me->set("str",13);
          me->set("force",9000);
          me->set("force-factor",0);
          say(HIR"�ø»��˫üһ˳���ָֻ���ί�Ҳ�������ӡ�\n"NOR);
          return 1;
        }
        if (( (int)ob->query("kee")/ his_max_qi) <5 ) 
        {
          say("�ø»��˫�ֺ�ʮ������Թ��𣬾��鳾����ʩ����ذɡ�

\n");
          message_vision("$N��Ȼ֮�����㲻�ȣ������˳�ȥ��\n", ob);
          ob->delete_temp("mark/���ϰ�");
          ob->move("/wiz/saying/work/linzhi/temple1");
          me->set_name("������",({"old lama","lama"}));
          me->set("nickname","��������");
          me->set("long","һ��������˥������Ѿ�û�����ͷ�ˡ�\n");
          me->set("combat_exp",25000);
          me->delete_skill("blade", 250);
          me->delete_skill("unarmed",250);
          me->delete_skill("parry", 250);
          me->delete_skill("dodge", 250);
          me->delete_skill("force", 250);
//        me->delete_skill("fire-blade", 250);
//        me->delete_skill("dashouyin", 250);
//        me->delete_skill("jimie-steps", 250);
//        me->delete_skill("mizong-xinfa", 250);
          me->set("str",13);
          me->set("force",9000);
          me->set("force-factor",0);
          say(HIR"�ø»��˫üһ˳���ָֻ���ί�Ҳ�������ӡ�\n"NOR);
          return 1;
        }
        return 1;
}
