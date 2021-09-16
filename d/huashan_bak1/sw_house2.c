// Room: /d/huashan/sw_house2.c

#include <ansi.h>

inherit ROOM;

void reset()
{
  ::reset();
  remove_call_out("reset");
  call_out("reset",random(7200)+7200);
  set("have_book",1);
}

void create ()
{
        set("short", "Сľ��");
    set("long", @LONG
������һ���ƾɵ�Сľ�ݣ�ľ�����泤�����Ӳݣ����м���
һ��Сľ�����������ҵİڷ���һЩ��ߡ�С�ݺ�ǽ����һ����
������������¯��һ�����(foxiang)��ǽ����һ������(lian)��
���ڿ���ƽ����������ǽ����Լ�ܹ���������ɫ��Ѫ�������˲�
������Ƥ���ͷƤ���顣
LONG
        );

  set("item_desc", ([ /* sizeof() == 2 */
  "foxiang" : "
һ�������ķ����ƺ��Ѿ������ˡ�
",
  "lian" : HIR"

�������� �� Ǳ ������

  ������     ������
  ������     ���ީ�
  ������     ������
  ��ɱ��     ����
  ������     ������
  ������     ���ީ�
  ������     ������
  ����     ������
  ������     ������
 ������   ��  ���ީ�
 ������   ��  ������
 ���ة�   ��  ������
 ������   ��  ������
 ��ͷ�� ��    ������
 ������ ��    ������

"NOR,
]));

  set("have_book", 1);

  set("light_up", 1);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"sw_house",
]) );

  setup();
}

void init()
{
   add_action("do_ketou","ketou");
   add_action("do_clear","clear");
   add_action("do_na_book","na");
}

int valid_leave(object me, string dir)
{
        if ( present("stone guard",environment(me)) )
           return notify_fail(RED"���������ߣ�����ȴ��ʯͷ�˵�ס�ˣ�\n"NOR);
    me->delete_temp("ketou_times");
    me->delete_temp("kk_guard_bot");
    me->delete_temp("clear_foxiang_ok");
    return ::valid_leave(me,dir);
}

int do_ketou(string str)
{
  object me = this_player();

  if (!me->query_temp("ketou_times"))
          me->set_temp("ketou_times",1);

  if (me->query_temp("ketou_times")>3 ||
          me->query_temp("ketou_times")==-1
          )
          me->set_temp("ketou_times",-1);
  else
      me->add_temp("ketou_times",1);

  message_vision("$N����������˸�ͷ��\n", me);

  return 1;
}

void kk_unlike_stranger(object me)
{
  int i, n=1;
  object ob;

  message_vision("$N���ڲ��÷���ͻȻһ��ǽ�ϵİ��Ŵ򿪣��߳��˼���ʯͷ�ˣ�$N���ɵô���һ�£�\n\n",me);
  message_vision("ʯͷ�˶���$N���Ӷ�������ı���ɱ�˹�����\n\n",me);

  if (random(me->query("kar"))<12)
          n++;

  for (i=0;i<n;i++)
  {
          ob=new(__DIR__"npc/guard_bot");
      ob->move(environment(me));
      ob->kill_ob(me);
  }
  me->start_busy(1);

}

int do_clear(string str)
{
  object me = this_player();

  if (!str || (str!="����" && str!="xiang" && str!="����" && str!="foxiang") )
          return notify_fail("��Ҫ����ʲô��\n");

  if (me->query_temp("clear_foxiang_ok"))
          return notify_fail("�����Ѿ����õķǳ��ɾ��ˡ�\n");

  if (!me->query_temp("kk_guard_bot"))
          me->set_temp("kk_guard_bot",1);

  if (present("stone guard",environment(me)))
  {
          if (me->is_fighting())
                  tell_object(me,"����æ��ս���ء�\n");
          else
                  tell_object(me,"���������񣬵���ʯͷ�˵�����һ�ۣ��ŵ��㲻�������֡�\n");
          return 1;
  }

  if (!me->query_temp("ketou_times") || // û��ketou
          (me->query_temp("ketou_time")!=-1 &&
           random(me->query("kar"))<10 &&
           random(10)<6) ||             // ��ͷ������+�Լ���ù
          (me->query_temp("ketou_time")==-1 &&
           random(me->query("kar"))<5 &&
           random(10)<3) ||             // ��ͷ���˵����Լ���ù
           me->query_temp("kk_guard_bot")<2             // û��ɱ���㹻��ʯͷ��
          )
  {
          kk_unlike_stranger(me);
          return 1;
  }

  tell_object(me, "������ŷ��񣬺�Ȼ����ǽ�ϴ���һ������\n");

  me->set_temp("clear_foxiang_ok",1);
  call_out("do_close_box",5,me);
  return 1;
}

int do_na_book(string str)
{
  object env;
  object me = this_player();

  if (!str || (str!="�־�" && str!="book" && str!="shoujuan" && str!="miji") )
          return notify_fail("��Ҫ��ʲô��\n");

  if (me->query_temp("clear_foxiang_ok")!=1)
          return notify_fail("��Ҫ��ʲô��\n");

  env=environment(me);

  me->delete_temp("ketou_times");
  me->delete_temp("kk_guard_bot");
  me->delete_temp("clear_foxiang_ok");

  // 2~4Сʱ����һ��
  if (!env->query("have_book"))
  {
        tell_object(me, "���ڰ����������˰��죬����ʲô��û���ҵ���\n");
        return notify_fail("����֨֨�����Զ������ˡ�\n");
  }


  remove_call_out("do_close_box");
  env->set("have_book", 0);
  tell_object(me, "���ڰ��������ҵ���һ���ƾɵ��־�\n");
  tell_object(me, "����֨֨�����Զ������ˡ�\n");
  new(__DIR__"obj/shoujuan")->move(me);
  return 1;

}

void do_close_box(object me)
{
  me->delete_temp("ketou_times");
  me->delete_temp("kk_guard_bot");
  me->delete_temp("clear_foxiang_ok");

  tell_object(me, "����֨֨�����Զ������ˡ�\n");
}
