// Room: /u/w/wangs/b/kai25.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������һ�������С������Ǿ����������ĸ߸ߵ���ש
Ժǽ�������ɫ��Ժǽ�ϼ���ż��Ƚ��յĴ��š����������
�������⣬���Ը���һ������ɭɭ�ĸо�������һ�����ɫ�Ĵ�
��ȴ�ǳ����ģ��ű߹���һ�����ƣ�����д�š����ʡ��������֡�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"kai27",
  "south" : __DIR__"kai26",
  "west" : __DIR__"kai23",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
