// Room: /d/huashan/c_forst.c

#include <ansi.h>

inherit ROOM;

void create ()
{
        set("short", HIC"��ɽ����"NOR);
    set("long", @LONG
������һ��ï�ܵ����֣���Ȼ��ľ���࣬ȷû�п����κλ�
���Ϊ�����䣬�������еĺ�ɽ����֦ͷ����һ˿��˪����
�㲻�ɵò������⣺Ҳ���ٶ�ͣ��Ƭ���Լ��ͻ���һ�����ɣ�
���ǿ�Щ�뿪����ط������ڶຮɽ���У���һ�ú�ɽ��(song)
ʮ�ֵĸ���ͦ�Σ������а�������䡣��������������������·��
������һ��СϪ������һ���ݵء�
LONG
        );

  set("item_desc", ([ /* sizeof() == 2 */
  "song" : "
һ������ĺ�ɽ������������һЩ��ֵ�ʯͷ(stone)��
",
  "stone" : "
ʯͷ�������һЩ���֡�
",
]));

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"m_down",
  "east" : __DIR__"c_spring",
  "southwest" : __DIR__"f_road1",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_learn","lingwu");
   add_action("do_learn","practise");
   call_out("greeting",1,this_player());
}
 
void greeting(object me)
{
        int t=0;

        remove_call_out("greeting");
        if ((me->query("kee",1)<15 || me->query("gin",1)<10) &&
                !me->query_temp("unconcious"))
        {
                message_vision("$N�����Ļ��˹�ȥ��\n",me);
        me->unconcious();
                me->set("kee",100);
                me->set("sen",100);
                me->set("gin",100);
                call_out("greeting",3+random(3),me);
                return;
        }

    me->add("kee",-5-random(5));
    me->add("gin",-3-random(3));
        t=(int)me->query("kee",1)*100/me->query("max_kee",1);
    if (t>80) 
                message_vision(HIC"$N������ĺ�������ֱ���£���ͣ�Ĵ����硣\n"NOR,this_player());
        else if (me->query("kee",1)>60) 
                message_vision(HIC"$N���������һ�󣬾����ֽ���Щ��ͣʹ���ˡ�\n"NOR,this_player());
        else if (me->query("kee",1)>40) 
                message_vision(HIB"$N�������彩Ӳ������������Щ���ѡ�\n"NOR,this_player());
        else if (me->query("kee",1)>20) 
                message_vision(HIB"$N������䣬�ƺ�Ҫ��Ϊһ�������ˣ�\n"NOR,this_player());
        else
                message_vision(HIB"$N���۶��¡��䡭���䰡����\n"NOR,this_player());
        if ( !me->query_temp("unconcious") )
            call_out("greeting",3+random(3),me);
}

int valid_leave(object me, string dir)
{
    remove_call_out("greeting");
    return ::valid_leave(me,dir);
}

int do_learn(string str)
{
   object me = this_player();

   if (!str)
          return notify_fail("��Ҫ����ʲô��\n");

   if (str!="stone" && str!="ʯ��" && str!="shibei" && str!="ʯͷ")
      return notify_fail("��Ҫ����ʲô��\n");

   if (!(int)me->query_skill("literate"))
      return notify_fail("����ϸ���˿�ʯ���ϵ����֣�����ȴ�޷�֪�����еĺ��塣\n");

   // �Ƿ�һ��Ҫ��ɽ�����أ�������һ��
   // �������ɵ���Ҳ����ѧ�����ǻ�ɽ���ӿ���ѧ�ĸ��� to 421
   //if ( (string)me->query("family/family_name")!="��ɽ��" )
//        return notify_fail("ʯ����д���ǻ�ɽ�ɵĽ���Ҫ�죬�ƺ����ʺ��㡣\n");

   if ((int)me->query_skill("literate")>=401 &&
           (string)me->query("family/family_name")!="��ɽ��" )
      return notify_fail(HIY"�㿴�˿�ʯ���ϵ����֣��ƺ�û��ʲô����ѧ�ġ�\n"NOR);

   // for huashan dizi
   if ((int)me->query_skill("literate")>=421 &&
           (string)me->query("family/family_name")=="��ɽ��" )
      return notify_fail(HIY"�㿴�˿�ʯ���ϵ����֣��ƺ�û��ʲô����ѧ�ġ�\n"NOR);

   if ((int)me->query("kee") < 150 ||
           (int)me->query("sen") < 80  ||
           (int)me->query("force") < 150 )
          return notify_fail("���Ѿ���ƣ��������������ȥ���߻���ħ�ġ�\n");

   if (random(100)<50)
      tell_room(environment(me), this_player()->query("name")+
                "���ڶ���ʯ��������\n",
                ({me}));
   else
      tell_room(environment(me), this_player()->query("name")+
                "���������㵸�ıȻ���ʲô��������˷ܵ����ӡ�\n",
                ({me}));

   tell_object(me, WHT"����ϸ�о���ʯ���ϵ����֣��ڽ������������µ���ʶ��\n"NOR);
   tell_object(me, YEL"�����ʯ���ϵ�������ϰ����������\n"NOR);

   me->receive_damage("kee", 90+random(20));
   me->add("force", -90-random(20));
   me->add("sen", -40-random(20));
   me->improve_skill( "sword", 
           me->query_skill("literate")+me->query_skill("sword")/10+random(me->query_skill("literate"))*10 );

   // ��ֹplayer�����뿪room�İ취�ӱܡ������˺���
   me->start_busy(1);

   return 1;
}

