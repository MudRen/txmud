// Room: /wiz/louth/a/shandong5.c

inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
�����ǿ�����Ĵ�ɽ�������ܵ�ʯ��(wall)���ʮ��ƽ����
������ż�ֻ��ȼ�Ļ�ѣ���������ϸϸ��ɳ�ӣ�����ȥ������
�ʡ�ǰ����Լ͸����һ�����⣬��ž��Ƕ����ˡ�
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "ʯ��" : "[1;37m
                ��      ��
                ��      Ȼ
                Ʈ      һ
                ��      Ц
                Ц      Ϸ
                ��      ��
                ��      ��

[2;37;0m",
  "wall" : "[1;37m
                ��      ��
                ��      Ȼ
                Ʈ      һ
                ��      Ц
                Ц      Ϸ
                ��      ��
                ��      ��

[2;37;0m",
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong3",
  "north" : __DIR__"taoyuan1",
]));

	setup();
	replace_program(ROOM);
}
