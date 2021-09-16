// shoujuan.c
#include <ansi.h>
inherit ITEM;void create(){     set_name( "破旧的手卷", ({ "shoujuan", "book", "miji" }));     set_weight(200);
        set("read_times",-1);   if( clonep() )          set_default_object(__FILE__);   else {          set("unit", "本");              set("long", "这是一个落满尘土的手卷。\n");          set("value", 100);              set("material", "paper");       }}
int init()
{
        add_action("lingwu_book","du");
        add_action("lingwu_book","comp");
        add_action("lingwu_book","lingwu");
}


int lingwu_book(string str)
{
  object ob = this_object();
  object me = this_player();

  if (!str || (str!="手卷" && str!="book" && str!="shoujuan" && str!="miji") )
          return notify_fail("你要读什么？\n");

  if (me->query("dugu_pfm_dang"))
          return notify_fail("你无法从这个手卷中领悟到新的东西了。\n");
  
  if (!me->query_skill("literate"))
          return notify_fail("你像模像样的看了半天，但是…咳……一个字都看不懂。\n");

  if (me->query_skill("literate",1)<100)
          return notify_fail("你仔细的看了半天，但是里面的知识对于你来说太难懂了。\n");

  if (me->query("combat_exp",1)<3000000)
          return notify_fail("你的实战经验不够，无法领悟这个手卷中的知识。\n");

  if (me->query("potential",1)<5000)
          return notify_fail("你的潜能不够，无法领悟其中的奥妙。\n");

  if (me->query_skill("huashan-sword") ||
          !me->query_skill("dugu-sword")
          )
          return notify_fail("你的研读了半天，发现这本书上的功夫并不适合你。\n");

  if (me->query_skill("dugu-sword",1)<180)
          return notify_fail("你的研读了半天，但是由于你的基本功只是粗通皮毛，所以无法掌握书中的秘诀。\n");
  
  tell_object(me,BLU"你开始认真的按照手卷中所写的要领开始运气，打通经脉。\n\n"NOR);
  me->start_busy(3);
  remove_call_out("do_master");
  call_out("do_master",3,ob);
  return 1;
}

int do_master(object ob)
{
  object me = this_player();

    if (me->query("potential")<5000)
        {
           tell_object(me,"你的潜能不够，无法领悟其中的奥妙。\n");
           return 0;
        }

        if (ob->query("read_times")==-1)
        {
                ob->set("read_times",1);
        }

        switch (ob->query("read_times"))
        {
        case 1:
        tell_object(me,HIB"你感觉身体内好像有一股如清泉的气，在缓缓流动着。\n\n"NOR);
                ob->add("read_times",1);
                me->start_busy(3);
        call_out("do_master",3,ob);
                return 1;
                break;
        case 2:
        tell_object(me,HIC"你觉得身体非常轻盈，于是按照口诀练习着剑法。\n\n"NOR);
                ob->add("read_times",1);
                me->start_busy(4);
        call_out("do_master",4,ob);
                return 1;
                break;
        case 3:
                ob->add("read_times",1);
        tell_object(me,HIW"恍惚之间，你豁然开朗，对着手卷放声大笑。\n\n"NOR);
        tell_object(me,HIW"你终于领悟到独孤九剑『荡剑式』的奥妙！\n\n"NOR);
                me->set("dugu_pfm_dang",1);
                me->add("potential",-5000);
                if (me->query("potential")<0)
                        me->set("potential", 0);
        remove_call_out("do_master");
                destruct(ob);
                return 1;
                break;
        default:
        tell_object(me,HIY"你忽然感觉有些不适，无法继续练习下去。\n"NOR);
        remove_call_out("do_master");
                destruct(ob);
                return 0;
                break;
    }

        return 1;
}
