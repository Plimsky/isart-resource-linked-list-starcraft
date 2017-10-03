TARGET  = app

CC       = gcc
CFLAGS   = -I./includes

LINKER   = gcc
LFLAGS   = -I./includes

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(shell find $(SRCDIR) -name '*.c')
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM       = rm -rf

all: $(BINDIR)/$(TARGET) | $(BINDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: fclean
fclean: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

re  : fclean all
