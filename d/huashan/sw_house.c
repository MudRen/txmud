// Room: /d/huashan/sw_house.c

inherit ROOM;

void create ()
{
        set("short", "Сľ����");
    set("long", @LONG
��������һ���ƾɵ�Сľ�ݣ�ľ����Χ��Щ��ʣ������Ѿ�
�������Ӳݣ��ƺ��ܶ���û����������ס���ˡ�
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"sw_house2",
  "north" : __DIR__"f_road2",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}


