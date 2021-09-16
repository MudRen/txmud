// mp_book.c

inherit ITEM;

protected string my_long = "
               ˜¡÷√‘π¨Õº

                 ±±

%s
";


string query_my_long() { return my_long; }

protected void create()
{
	set_name(" ˜¡÷√‘π¨Õº", ({ "shulin map" }) );
	set_weight(100);
	set("unit", "’≈");
	set("long", (: query_my_long :));
}

void set_my_map(string mm)
{
	if(!stringp(mm) || !sizeof(mm))
		return;

	my_long = sprintf(my_long, mm);
}
