// Room: /d/changan/sroad5.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ǵ��ϴ�֣�����һ���ǳ����Ϸ����ĵضΣ���������
�������������Ǹ������Ŀ��ã�����һЩ�������ʹ�ڣ�Ҳ����
�￴���й�����磬���ֵ���С�����������ˣ�æ�Ĳ����ֺ���
������С�������ڷ����ľ�����Ҳ����һ�󾰹ۡ�
LONG
	);
	set("outdoors", "changan");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"sroad6",
  "west" : __DIR__"sroad4",
  "north" : __DIR__"jinghu",
]));

	setup();
	replace_program(ROOM);
}
