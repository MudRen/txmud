// Room: /u/w/wangs/a/yu22.c

inherit ROOM;

void create()
{
	set("short", "�����Ժ");
	set("long", @LONG
�����������Ժ���ߵ��������ζ����Ũ���ˡ���
��ϸһ�����������������Ļ��ݣ�һȺȺ�۷䡢�����ڻ�
���з��衣�������������ȣ�����������Ĵ�����
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu37",
  "north" : __DIR__"yu21",
  "west" : __DIR__"yu31",
  "east" : __DIR__"yu23",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
