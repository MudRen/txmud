// Room: /d/huashan/f_road2.c

inherit ROOM;

void create ()
{
        set("short", "����·");
    set("long", @LONG
������һ������С·���������ľʮ�ַ�ï���������͸��
�����ϣ���˶��˼��ֺ��⡣�����зǳ���������Ұ�޷��ݵ���
��������������������������һ��Сľ�ݣ��򶫱�������·��
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"f_road1",
  "south" : __DIR__"sw_house",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}


