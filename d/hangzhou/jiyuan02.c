// Room: /d/hangzhou/jiyuan02.c

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
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jiyuan01",
  "south" : __DIR__"jiyuan04",
  "east" : __DIR__"jiyuan05",
  "north" : __DIR__"jiyuan03",
]));

	setup();
	replace_program(ROOM);
}
