// Room: /d/hangzhou/jiyuan04.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ��������ȣ����ȵ���һ������λ����Ĺ뷿����
�����ȵĶ���ÿ�����߾���һյ���ƣ��ڵƹ��ӳ�³����ֵ÷�
����ܰ����ÿλ����ķ����ſڻ����Ҹ�һ�����򣬵��������
ʱ����ζ�Ź���ڴˣ�������š�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jiyuan07",
  "north" : __DIR__"jiyuan02",
]));

	setup();
	replace_program(ROOM);
}
