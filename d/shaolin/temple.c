// Room: /wiz/uudd/path2/temple.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��һ��С��ׯ�ﳣ���ܼ�����С����ʱ��һ������
��������㣬�����������и����ճɣ����������ϵ����ӣ���
����������Щ��Ц�����㲻�����룺������ѽ�����������ڵ�
���ͱ������ǰɣ���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"k_s12",
]));

	setup();
	replace_program(ROOM);
}
