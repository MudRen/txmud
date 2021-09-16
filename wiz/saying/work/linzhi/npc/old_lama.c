//old_lama.c 济嘎活佛，不过表面上是个毫无用处的老喇嘛。
#include <ansi.h>
inherit NPC;
int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
        set_name("老喇嘛", ({ "old lama","lama"}) );
        set("nickname", "无我无欲");
        set("gender", "男性" );
        set("age", 57);
        set("str", 13);
        set("cor", 10);
        set("cps", 50);
        set("int", 66);
        set("per", 18);
        set("con", 54);
        set("spi", 30);
        set("kar", 25);
        set("long","一个年老体衰的喇嘛，已经没几年活头了。\n");
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
        "黄升发":(:ask_me:),
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
        else if (!(int)ob->query_temp("mark/总老板"))
        {
        say(CYN"老喇嘛说道：往生法？我密宗中无此功法。\n"NOR);
        return 1;
        }
        else
        {
        me->set_name("济嘎活佛",({"jiga huofo","huofo"}));
        me->set("nickname",HIR"宁玛教宗"NOR);
        me->set("long","本寺方丈济嘎活佛，密宗高手。\n");
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
        say(HIC"老喇嘛忽然肃容而立，全身泛出一种大高手的风范。\n"NOR);
        say(CYN"老喇嘛说道：老衲就是济嘎。\n"NOR);
        say(CYN"济嘎活佛说道：既然是我种下此因，就让我了结此果。施主请出招吧。\n"NOR);
        say(CYN"济嘎活佛说道：我们点到为止。\n"NOR);
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
        say(CYN"济嘎活佛说道：好吧，那我就同你切搓几招吧，点到为止。\n"NOR);
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        return 1;
        }
        else
        {
        say(CYN"济嘎活佛说道：我现在有点累，你先等会儿。\n"NOR);
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
          say(CYN"济嘎活佛说：施主身手果然不凡，老衲佩服。这本火焰刀谱你拿去吧。\n"NOR);
          obj=new(__DIR__"obj/fire_book1"); 
          if (!objectp(obj))
          obj=new(__DIR__"obj/fire_book2");
          obj->move(ob);
          message_vision("$N交给$n一本书。\n", me, ob);
          ob->delete_temp("mark/总老板");
          me->set_name("老喇嘛",({"old lama","lama"}));
          me->set("nickname","无我无欲");
          me->set("long","一个年老体衰的喇嘛，已经没几年活头了。\n");
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
          say(HIR"济嘎活佛双眉一顺，又恢复了委靡不振的样子。\n"NOR);
          return 1;
        }
        if (( (int)ob->query("kee")/ his_max_qi) <5 ) 
        {
          say("济嘎活佛双手合十道：恩怨情仇，尽归尘土，施主请回吧。

\n");
          message_vision("$N忽然之间立足不稳，倒飞了出去。\n", ob);
          ob->delete_temp("mark/总老板");
          ob->move("/wiz/saying/work/linzhi/temple1");
          me->set_name("老喇嘛",({"old lama","lama"}));
          me->set("nickname","无我无欲");
          me->set("long","一个年老体衰的喇嘛，已经没几年活头了。\n");
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
          say(HIR"济嘎活佛双眉一顺，又恢复了委靡不振的样子。\n"NOR);
          return 1;
        }
        return 1;
}
