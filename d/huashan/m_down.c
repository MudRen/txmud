// Room: /d/huashan/m_down.c

inherit ROOM;

void create ()
{
        set("short", "ɽ����");
    set("long", @LONG
������һ����᫵��ݵأ�ǰ���ƺ���һƬï�ܵ�ɭ�֣�ȴ��
�������һ�����ɫ������һ�뻷ɽ�����������ţ�����������
����ܶ���û���������������������߿��Խ���һƬ���֡�
LONG
        );

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"c_forst",]) );

  set("outdoors", "/d/huashan" );
  set(SAFE_ENV, 1);
  set("user_compare",1);

  //set("outdoors", "/open/soulin" );

  setup();
}

void init()
{
   add_action("do_climb","climb");
}

//if ( (string)ob->query("family/family_name")=="��ɽ��" ) return 1;

int do_climb(string str)
{
   object me = this_player();
   if (!str)
       return notify_fail("��Ҫ�ʵ����\n");
   if (str!="up" && str!="shan")
       return notify_fail("��Ҫ�ʵ����\n");

   if (me->query("kee",1)<50 || me->query("gin",1)<30)
   {
           message_vision("$Nһ����С�ģ��Ӱ�ɽ���ϵ���������\n",this_player());
           me->unconcious();
           return 0;
   }  

   me->add("kee",-45);
   me->add("gin",-25);
   message_vision("ֻ��$N������������������ȥ��\n",this_player());
   me->start_busy(2);
   me->move(__DIR__"bxuanya.c");
   return 1;
}

