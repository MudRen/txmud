// Room: /d/tangmen/yz_tang.c

inherit ROOM;

void create()
{
	set("short", "��ҩ��");
	set("long", @LONG
����һ�䲻��ķ��䣬����������һ����̨������֧��һ��
��ɳ������ཹ�ཱུ����������ⶼ��������һ��Сͯ����������
�ŷ��䣬��һ���ڿ��Ź��ﲻʱ�ķŽ�һЩҩ�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"yz_xiaoyuan",
]));

	setup();
	replace_program(ROOM);
}
