// shulin2.c ���� 

inherit ROOM;
void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
һ����С����ʯ�̳ɵ�С·���ּ����죬��Ҷ��΢�紵����
��ˢˢ�����죬ż�������ּ�������ͷ���ɹ������ߵ�������
�·��������Ĵ�������
LONG
        );
       set("exits", ([
                "west"              : __DIR__"shulin",
                "east"              : __DIR__"kongdi",
                  "south"             : "/d/path2/ch_k24",
                     ]) );
       set("outdoors","wenchuan");
       setup();
       replace_program(ROOM);
}
