// Room: /d/huanggong/jiulb.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����������������Ĵ��ھ����ڡ�������ɫ�����̾��ڱ���
ɫ�Ļ����ϡ��ɶ��칤���ֱ����˾�̾����������ɲ����������
�����ư��硣�޴��ǰצ����ץ������֮�ϣ��߽�һ����������
���������ײ���β�����������ص�ɫ�ʡ��򱱾͵��˻ʼ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jingym",
  "north" : __DIR__"huangjd",
]));
        set("no_clean_up", 0);

	set("outdoors", "huanggong");
        setup();
        replace_program(ROOM);
}

