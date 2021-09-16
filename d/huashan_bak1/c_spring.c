// Room: /d/huashan/c_spring.c

inherit ROOM;

void create ()
{
        set("short", "СϪ");
    set("long", @LONG
������һ�������ĺӰ���һ��СϪ��ɽ���������Ӱ���Χ��
��һЩ��˪��Ҳ���������꺮���Ե�ʰɡ���������������һ
Ƭ��ɽ���֡�
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"c_forst",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_drink","drink");
}
 
int do_drink(string str)
{
   object me = this_player();

   if (!str || (str!="water" && str!="spring"))
      return 0;

   if ( me->query("water",1)>=me->max_water_capacity() )
   {
           tell_object(me, "���Ѿ��ȵ�̫�࣬��Ҳ�Ȳ���ȥ�ˡ�\n");
           return 1;
   }

   tell_room(environment(me), this_player()->query("name")+
                "���˼���Ȫˮ��\n",
                ({me}));

   tell_object(me, "����˼���Ȫˮ��\n");

   me->add("water", 30);
   return 1;
}

