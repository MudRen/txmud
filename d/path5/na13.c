// Room: /d/path5/na13.c

inherit ROOM;

void create()
{
	set("short", "�ƾ�Ҥ��");
	set("long", @LONG
����ƾ�Ҥ������������Ϻ��ļң�����ʮ�ּ�ª�����˱�
���������Ʒ��Щ���ʲô��û�С����Ϻ������������ǵ�Ǯ��
�����϶������˾ò����ε�Ů����ϼ���ϣ��κ�Ů����������
�����Ը�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"na12",
  "east" : __DIR__"na14",
]));
	setup();
	replace_program(ROOM);
}
