//lama.c ²Ø×åÀ®Âï¡£
inherit NPC;
void create()
{
        set_name("À®Âï", ({ "lama" }) );
        set("age", 33);
        set("long", "µÂÄ¾ËÂµÄÀ®Âï¡£\n");
        
        set("str",25);
        set("per",10);
        set("inquiry",([
        "µÂÄ¾ËÂ":"Ğ¡É®¾ÍÊÇµÂÄ¾ËÂµÄÀ®Âï¡£",
]));        
        setup();
        carry_object(__DIR__"obj/cassock")->wear();
}
