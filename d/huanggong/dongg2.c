// Room: /d/huanggong/dongg2.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
������ź󣬽������߽��������ȡ��������۵Ļ����У���
���Ƴɵĳ��Ƽ��Ϲ���һ�������Ĺ��ƣ���һ�������λ����ĳ�
���ϵ�̻������ʻ��ͼ�Σ�����ʤ�ա��ߵ����԰��������
�滨��ݣ�����������һ�ֵ������� ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"donggdm",
  "north" : __DIR__"dongg5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

