// shoujuan.c
#include <ansi.h>
inherit ITEM;void create(){     set_name( "�ƾɵ��־�", ({ "shoujuan", "book", "miji" }));     set_weight(200);
        set("read_times",-1);   if( clonep() )          set_default_object(__FILE__);   else {          set("unit", "��");              set("long", "����һ�������������־�\n");          set("value", 100);              set("material", "paper");       }}
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

  if (!str || (str!="�־�" && str!="book" && str!="shoujuan" && str!="miji") )
          return notify_fail("��Ҫ��ʲô��\n");

  if (me->query("dugu_pfm_dang"))
          return notify_fail("���޷�������־��������µĶ����ˡ�\n");
  
  if (!me->query_skill("literate"))
          return notify_fail("����ģ�����Ŀ��˰��죬���ǡ��ȡ���һ���ֶ���������\n");

  if (me->query_skill("literate",1)<100)
          return notify_fail("����ϸ�Ŀ��˰��죬���������֪ʶ��������˵̫�Ѷ��ˡ�\n");

  if (me->query("combat_exp",1)<3000000)
          return notify_fail("���ʵս���鲻�����޷���������־��е�֪ʶ��\n");

  if (me->query("potential",1)<5000)
          return notify_fail("���Ǳ�ܲ������޷��������еİ��\n");

  if (me->query_skill("huashan-sword") ||
          !me->query_skill("dugu-sword")
          )
          return notify_fail("����ж��˰��죬�����Ȿ���ϵĹ��򲢲��ʺ��㡣\n");

  if (me->query_skill("dugu-sword",1)<180)
          return notify_fail("����ж��˰��죬����������Ļ�����ֻ�Ǵ�ͨƤë�������޷��������е��ؾ���\n");
  
  tell_object(me,BLU"�㿪ʼ����İ����־�����д��Ҫ�쿪ʼ��������ͨ������\n\n"NOR);
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
           tell_object(me,"���Ǳ�ܲ������޷��������еİ��\n");
           return 0;
        }

        if (ob->query("read_times")==-1)
        {
                ob->set("read_times",1);
        }

        switch (ob->query("read_times"))
        {
        case 1:
        tell_object(me,HIB"��о������ں�����һ������Ȫ�������ڻ��������š�\n\n"NOR);
                ob->add("read_times",1);
                me->start_busy(3);
        call_out("do_master",3,ob);
                return 1;
                break;
        case 2:
        tell_object(me,HIC"���������ǳ���ӯ�����ǰ��տھ���ϰ�Ž�����\n\n"NOR);
                ob->add("read_times",1);
                me->start_busy(4);
        call_out("do_master",4,ob);
                return 1;
                break;
        case 3:
                ob->add("read_times",1);
        tell_object(me,HIW"���֮�䣬���Ȼ���ʣ������־������Ц��\n\n"NOR);
        tell_object(me,HIW"���������򵽶��¾Ž�������ʽ���İ��\n\n"NOR);
                me->set("dugu_pfm_dang",1);
                me->add("potential",-5000);
                if (me->query("potential")<0)
                        me->set("potential", 0);
        remove_call_out("do_master");
                destruct(ob);
                return 1;
                break;
        default:
        tell_object(me,HIY"���Ȼ�о���Щ���ʣ��޷�������ϰ��ȥ��\n"NOR);
        remove_call_out("do_master");
                destruct(ob);
                return 0;
                break;
    }

        return 1;
}
