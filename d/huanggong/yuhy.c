// Room: /d/huanggong/yuhy.c

inherit ROOM;

void create()
{
        set("short", "����԰");
        set("long", @LONG
���������������������԰�����漸���㼯���˼����е���
������ݣ�ÿ��̤��԰�ž�ʹ����һ���Ŀ������ĸо�����Ŀ��
ȥ��԰��ʢ����ǧ�˰�̬������ĵ������Ȼ�䣬���ŵ�һ������
��Ƣ�����㣬������ͷ��ȥ���ۣ��ô��һ��ٺϻ�����������
��������������������ͤ�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yanhg",
  "west" : __DIR__"taihjs",
  "south" : __DIR__"kunng",
  "north" : __DIR__"qinad",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
	setup();
	replace_program(ROOM);
}