// Room: /d/huashan/f_road1.c

inherit ROOM;

void create ()
{
        set("short", "����·");
    set("long", @LONG
������һ������С·���������ľʮ�ַ�ï���������͸��
�����ϣ���˶��˼��ֺ��⡣�����зǳ���������Ұ�޷��ݵ���
�������������������򶫱�����һƬ��ɽ���֣�������������·��
LONG
        );

  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"c_forst",
  "southwest" : __DIR__"f_road2",
]) );

  set("outdoors", "/d/huashan" );
  //set("outdoors", "/open/soulin" );

  setup();
}


