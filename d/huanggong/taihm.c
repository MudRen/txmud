// Room: /d/huanggong/taihm.c

inherit ROOM;

void create()
{
        set("short", "̫����");
        set("long", @LONG
������ǻʹ������Ĺ㳡��ÿ�����Ͼ��д���ʱ�򣮶�
�������������̶ӣ����ƺ���������˵��������ɣ�̧ͷ��ȥ
���ߺ�ǽ���������˻ʹ��ĸ����ûʣ��������߾��ǹ���Ȩ����
�ĵ�������̫�͵
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"daolu4",
  "west" : __DIR__"daolu2",
  "south" : __DIR__"wumen",
  "north" : __DIR__"taihd",
]));
      
        set("no_clean_up", 0);
        set("outdoors", "huanggong");
        replace_program(ROOM);
}