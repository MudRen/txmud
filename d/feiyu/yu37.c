// Room: /u/w/wangs/a/yu37.c

inherit ROOM;

void create()
{
	set("short", "�����Ժ");
	set("long", @LONG
�����������Ժ���ߵ��������ζ����Ũ���ˡ���
��ϸһ�����������������Ļ��ݣ�һȺȺ�۷䡢�����ڻ�
���з��衣�������������ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yu92",
  "north" : __DIR__"yu22",
  "west" : __DIR__"yu77",
  "east" : __DIR__"yu38",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
