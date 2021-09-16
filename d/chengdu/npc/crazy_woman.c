// crazy_woman.c
// find.

inherit NPC;

string ask_tangmen(object me);
protected void decide_to_enter(string, object);

void create()
{
	set_name("·èÆÅ×Ó", ({ "crazy woman" }) );
	set("gender", "Å®ÐÔ" );
	set("age", 53);
	set("attitude","peaceful");
	set("long", "ÕâÊÇÒ»Î»ÒÂÉÀñÜñÚµÄ·èÆÅ×Ó£¬
¿´Ñù×ÓÊÇ¸öÒª·¹µÄ¡£\n");
	set("combat_exp", 400);
	set("str", 20);
	set("force", 200);

	set("max_kee",9000);
	set_temp("apply/armor",300);
	set("env/wimpy",60);
	set_auto_recover(1);

	set("inquiry",([
	"ÊñÖÐ" : "·èÆÅ×ÓËµµÀ£º±ðËµÊÇÊñÖÐ£¬¾ÍÊÇÌìÏÂÎäÁÖÄãÎÊÎÊ¡£¡£¡£¡£ºÇ¡£¡£¡£¹þ¡£¡£¡£¡£\n",
	"ÊñÖÐÌÆÃÅ" : (: ask_tangmen :),
	"ÌÆÃÅ" : (: ask_tangmen :),
]));

	set("is_beggar",1);
	set("chat_chance", 8);
	set("chat_msg", ({
		"·èÆÅ×ÓºßºßßóßóËµµÀ£ºÊÀÈË¡£¡£¡£¶¼¡£¡£¡£Î¨ÓÐÎÒÄÜ¡£¡£¡£¡£¡£¡£\n",
		"·èÆÅ×ÓºßºßßóßóËµµÀ£ºË­²»ÖªµÀÊñÖÐ¡£¡£¡£°ÔÖ÷¡£¡£¡£\n",
	}) );

	setup();

	carry_object(ARMOR_DIR"cloth")->wear();
}

string ask_tangmen(object me)
{
	mapping family;

	if( mapp(family = me->query("family")) )
	{
		if(family["family_name"] == "ÊñÖÐÌÆÃÅ")
			return "ÉíÎªÌÆÃÅµÜ×ÓÒÔ¹â´óÃÅé¹¡¢³Æ°ÔÌìÏÂÎª¼ºÈÎ¡£\n";
		else
			return "¾ÍÖªµÀÄ¾ÃÅ¡¢ÖñÃÅ¡¢ÌúÃÅ£¬ÄÇÀïÓÐÌÇÃÅ´øÎÒÈ¥¿´¿´£¬Õâ»Ø²»ÓÃÒª·¹ÁË¡£¡£¡£\n";
	}

	if(me->query("class"))
		return "¾ÍÖªµÀÄ¾ÃÅ¡¢ÖñÃÅ¡¢ÌúÃÅ£¬ÄÇÀïÓÐÌÇÃÅ´øÎÒÈ¥¿´¿´£¬Õâ»Ø²»ÓÃÒª·¹ÁË¡£¡£¡£\n";

	if(me->query_temp("been_recommend_to_tangmen"))
		return "²»ÊÇºÍÄãËµÀ²£¡¸Ï½ôÈ¥£¬Ç§Íò±ðµ¢¸é£¡";


	if( (me->query("age") > 30)
	|| (me->query("cor") < 25)	// µ¨Ê¶
	|| (me->query("kar") < 25)	// ¸£Ôµ
	|| (me->query("int") < 25)	// ÎòÐÔ
	|| (me->query_skill("dodge",1) < 30)
	|| (me->query_skill("unarmed",1) < 30) )
		return "¾ÍÖªµÀÄ¾ÃÅ¡¢ÖñÃÅ¡¢ÌúÃÅ£¬ÄÇÀïÓÐÌÇÃÅ´øÎÒÈ¥¿´¿´£¬Õâ»Ø²»ÓÃÒª·¹ÁË¡£¡£¡£\n";

	tell_object(me, "·èÆÅ×ÓËµµÀ£ºÌÆÃÅÎä¹¦¶À²½ÌìÏÂ£¬ÌÆÃÅÓÃ¶¾¸üÊÇÈÃÈËÎÅÃûÉ¥µ¨£¡£¡
            ²»¹ýÒªÈëÌÆÃÅ£¬ÉúÊÇÌÆ¼ÒÈË£¬ËÀÊÇÌÆ¼Ò¹í£¡£¡Äã¸øÎÒ
            ºÃºÃ¿¼ÂÇÇå³þ¸Ò²»¸Ò½øÌÆÃÅ(y/n)£º");
	input_to((: decide_to_enter :), me);
	return "ºÃ¡£\n";
}

protected void decide_to_enter(string str, object me)
{
	object room, map_book;
	string mm;

	if(!me || (environment(me) != environment()) )
		return;

	if( !sizeof(str) || ((str[0] != 'y') && (str[0] != 'Y')) )
	{
		tell_object(me,"·èÆÅ×ÓºÙºÙÒ»ÕóÀäÐ¦ËµµÀ£º¡°Ô­À´ÊÇÄÃÀÏÄïÏûÇ²ÄÇ¡£¡£¡£¡±\n\nÄã¾õµÃÓÒÊÖÓÐµãÂé¡£\n\n");
		me->apply_condition("tangdu", 4);
		return;
	}

	if( !(room = find_object("/d/tangmen/shulin")) && !(room = load_object("/d/tangmen/shulin")) )
	{
		tell_object(me, "·èÆÅ×ÓËµµÀ£ºÌÆÃÅ³öÎÊÌâÀ²£¡£¡¿ìÕÒ¹ÜÀíÔ±£¡£¡¿ì£¡£¡\n");
		return;
	}

	if( !(mm = room->query_my_map()) || !(map_book = new(__DIR__"obj/mp_book")) )
	{
		tell_object(me, "·èÆÅ×ÓËµµÀ£ºÌÆÃÅµØÍ¼³öÎÊÌâÀ²£¡£¡¿ìÕÒ¹ÜÀíÔ±£¡£¡¿ì£¡£¡\n");
		return;
	}

	map_book->set_my_map(mm);

	tell_object(me, "\n·èÆÅ×ÓÕýÉ«ËµµÀ£ººÃ£¡¼ÈÓÐ´Ë¾öÐÄÎÒ¾Í³ÉÈ«Äã£¡£¡³öÁË³É¶¼ÄÏÃÅÒ»Ö±ÏòÄÏ
                ×ß£¬[1;34mÓöµ½²íÂ·¾ÍÏòÎ÷ÄÏ·½Ïò¹Õ[2;37;0m£¬µ½ÁËÃ»ÓÐÂ·µÄµØ·½Ê¹¾¢
                ÍÆÇ°ÃæµÄÊ¯Í·£¬[1;34mÏò×óÍÆÒ»ÏÂ(push left Ê¯Í·)£¬ÏòÓÒÍÆ
                ÎåÏÂ(push right Ê¯Í·)[2;37;0m£¬¾Í¿ÉÒÔ¹ýÈ¥ÁË¡£
                    ½øÁËÌÆÃÅ»áÓÐÒ»¸öÊ÷ÁÖµÄÃÔ¹¬£¬×¨ÃÅµÖÓùÍâÀ´Ö®ÈË£¬
                ÎÒ°ÑÃÔ¹¬µÄµØÍ¼¸øÄã£¬[1;34mÈç¹û²»´ø×ÅÍ¼£¬½øÈë±ØËÀÎÞÒÉ£¡[2;37;0m
                    ´ËµÈ»úÃÜ¾ö²»¿ÉÐ¹Â©¸øÍâÈË£¬ÎÒÒÑ¾­¸øÄãÏÂÁË»º·¢
                µÄ¶¾Ò©£¬[1;34mÈýÌìÖ®ÄÚÈç¹ûÄã²»°ÝÈëÌÆÃÅ£¬¾ÍÈÃÄãÈ«ÉíÀ£ÀÃ
                Í´¿à¶øËÀ[2;37;0m£¡£¡£¡¡£¡£¡£\n\n");

	if(!map_book->move(me))
	{
		tell_object(me, "·èÆÅ×ÓËµµÀ£ºÄãÉíÉÏÊ²Ã´Ò²ÄÃ²»ÏÂÁË£¬Ï¹µ·ÂÒ£¡£¡ÏûÇ²ÀÏÄï£¡£¡");
		me->apply_condition("tangdu", 4);
		return;
	}
	else
		tell_object(me,sprintf("·èÆÅ×Ó¸øÄãÒ»%s%s¡£\n", map_book->query("unit"),map_book->name()));

	me->set_temp("been_recommend_to_tangmen", 1);
	me->set("decide_enter_tangme_time", time());
	me->apply_condition("enter_tangmen", 1);
}

void die()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n·èÆÅ×ÓÉíÉÏÃ°³öÒ»ÂÆµ­µ­µÄÇàÑÌ¡£\n");
		inv->apply_condition("tangdu", 8);
	}
	::die();
}

void unconcious()
{
	object *inv, env;

	if(objectp(env = environment()) && sizeof(inv = filter_array(all_inventory(env), (: userp :))))
	{
		tell_room(env, "\n·èÆÅ×ÓÉíÉÏÃ°³öÒ»ÂÆµ­µ­µÄÇàÑÌ¡£\n");
		inv->apply_condition("tangdu", 8);
	}
	::unconcious();
}
