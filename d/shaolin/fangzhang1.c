// Room: /d/shaolin/fangzhang1.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����������µķ���������һ������һ�����������к��Ǽ�
�ӣ�����һ¯���һ�����ţ��տ���Ҳ�������ǽ����һ������
��ʦ����д�ġ������֡���������������ʯ����
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "couplet" : "      ����ҹ����Ӱ��\n      ɯͥ������Ŀ�\n",
  "����" : "      ����ҹ����Ӱ��\n      ɯͥ������Ŀ�\n",
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yongdao4",
]));

	set("objects",([
	__DIR__"npc/fangzhang" : 1,
]));

	setup();
	replace_program(ROOM);
}
