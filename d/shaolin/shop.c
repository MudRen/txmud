// Room: /wiz/uudd/path2/shop.c

inherit ROOM;

void create()
{
	set("short", "�ӻ���");
	set("long", @LONG
����˵�Ǹ��ӻ��꣬��ʵֻ�ǻ��˼ҡ������ڼ����ǽ�Ͽ�
��һ�����ڣ�װ�ϼ����Ű壬�Ͱ��Լ������ұ���̵��ˡ����
������ͷ������ȥ�����ﲢû�й�̨��ֻ��һ�Ű������������
�����ճ���Ʒ��һЩ��ʳ�������˾����ڴ��ϳ���һЦ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"k_s11",
]));

	setup();
	replace_program(ROOM);
}
