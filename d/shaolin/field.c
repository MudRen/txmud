// Room: /wiz/uudd/path2/field.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
������ɽ���µ�һƬ������ũ����ر���¢�ֳ�һ���һ
Ķ�����ķ��飬ɷ�����롣����ũ������������ͷ���֣�һ����
��Сͯ������ţ���Ϸ����質�����洫��һ�����֮����������
�����ӵ�ĸ�����ڻ��Ǹ����ӻؼҳԷ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"k_s10",
]));
	set("outdoors", "shaolin");

	setup();
	replace_program(ROOM);
}
