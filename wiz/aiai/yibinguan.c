// /d/changan/yibinguan  �Ǳ���


inherit ROOM;

void create()
{
        set("short", "�Ǳ���");
        set("long", @LONG
������Ǵӻʹ������Աߵ��Ǳ��ݣ�ƽʱ�������Ӵ���͵�
�ط������ҷ�����Ϣ��ʱ��Ҳ���͵���������и��ܻʹ��ճ�
�����̫�࣬��˵���ǻ��ϵ����š�
LONG
        );
       set("exits", ([
                "east"             : "/d/huanggong/beim"
]) );

       set("light_up", 1);
       set(SAFE_ENV, 1);

        set("objects", ([
                __DIR__"item_quest/quester" : 1,
        ]));

        setup();
//        replace_program(ROOM);
}

