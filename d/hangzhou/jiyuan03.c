// Room: /d/hangzhou/jiyuan03.c

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
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiyuan02",
  "east" : __DIR__"jiyuan06",
]));

	setup();
	replace_program(ROOM);
}
