// Room: /u/w/wangs/a/yu23.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ϣ������������ߣ�һ�ɸ������󡣱���
��ɽС��Ӧ�о��У��Ե�ʮ��������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"yu24",
  "west" : __DIR__"yu22",
]));
       set("outdoors","feiyu");

	setup();
	replace_program(ROOM);
}
